/*******************************************************************************
 * File: BTRecordFile.cpp
 * Author: Brallan Aguilar y Daniel Araya
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include <iomanip>
#include "BTRecordFile.h"

BTRecordFile::BTRecordFile(BTRecordFileMetadata * const pMetadata)
    : _metadataPtr(pMetadata)
{
    this->_registryArray = new BTRecord[100];
    this->_counter = 1;
    this->_listFreeBlocks = 0; // lista de bloques libres está vacía}
    this->_sizeOwner_FileName = 24;
    this->_cantidadDatosUser = -1; // no hay
    this->_conversion = new Converter();
    _disk = new Disk(1, 7); // id del disco/tamaño en megas disco/tamaño bloque bytes
    this->_idNextBlock = " "; // es nulo pues no hay siguiente
}

/**
 * @brief BTRecordFile::maxSizeOfRegistryInBlock
 * @return máxima cantidad de registros que caben en un bloque
 */
unsigned short BTRecordFile::getMaxSizeOfRegistryInBlock() const
{
    return _maxSizeOfRegistryInBlock;
}

void BTRecordFile::setMaxSizeOfRegistryInBlock(unsigned short maxSizeOfRegistryInBlock)
{
    _maxSizeOfRegistryInBlock = maxSizeOfRegistryInBlock;
}

/**
 * @brief BTRecordFile::computeMaxSizeOfRegistryInBlock
 * @return calcula max cantidad de registros por bloque
 */
unsigned short BTRecordFile::computeMaxSizeOfRegistryInBlock()
{
    int p = (this->_disk->getBlockSize() / this->_metadataPtr->getRecordSize());
    return p;
}

std::string BTRecordFile::getIdNextBlock() const
{
    return _idNextBlock;
}

void BTRecordFile::setIdNextBlock(const std::string &idNextBlock)
{
    _idNextBlock = idNextBlock;
}

/**
 * @brief BTRecordFile::getRegistryArray
 * @return _registryArray
 * Obtiene el arreglo de los los registros insertados en RAM
 */
BTRecord *BTRecordFile::getRegistryArray() const
{
    return _registryArray;
}

void BTRecordFile::setRegistryArray(BTRecord *pRegistryArray)
{
    _registryArray = pRegistryArray;
}

Disk *BTRecordFile::getDisk() const
{
    return _disk;
}

void BTRecordFile::setDisk(Disk *pDisk)
{
    _disk = pDisk;
}

BTRecordFileMetadata *BTRecordFile::getMetadata() const
{
    return _metadataPtr;
}

void BTRecordFile::setMetadata(IMetadata *pMetadataPtr)
{
    _metadataPtr = (BTRecordFileMetadata*)pMetadataPtr;
}

DLL<IRecord *> *BTRecordFile::getRecordList() const
{
    // TODO Se encarga de reconstruir desde el disco todos los registros

    return nullptr;
}

void BTRecordFile::setRecordList(DLL<IRecord *> *)
{
    // No es necesario establecer una lista de datos
}

//------------------------------------------------------------------------------
//   INSERCION DE DATOS EN DISCO
//------------------------------------------------------------------------------
/**
 * @brief BTRecordFile::insertRecord2Disk
 * @param pListPtr
 * Función que se encargará de insertar los registros al disco
 */
void BTRecordFile::insertRecord2Disk(DLL<IRecordDataType *> *pListPtr)
{
    unsigned short cantRegistros = this->_metadataPtr->getNumberOfRecords();
    unsigned short tamanoRegistro = this->_metadataPtr->getRecordSize();
    unsigned short posicionPrimerRegistro = this->_metadataPtr->getFirstRecordPos();
    std::string dataBinaryRecord;  // concatenacion del registro a binario
//    if ( computeMaxSizeOfRegistryInBlock() > cantRegistros ){
//        cout << "No se puede insertar" << endl;
//    }
//    else{
    if (this->_metadataPtr->getFreeBlockList() == 0) {
        if (cantRegistros == 1) {
            this->_disk = new Disk(1, 7);
            dataBinaryRecord  = "000000000000000000000000"; // No tiene ni padre ni hijos
        } else { // se insertan otros registros después de haber uno
            cout << "CANTIDAD DE REGISTROS--> " << cantRegistros << endl;
            unsigned short fatherPosition = posicionPrimerRegistro +
                                            ((tamanoRegistro) * ((cantRegistros / 2) - 1));
            std::string leftChild = "00000000";       // obtiene el hijo izq
            std::string rightChild = "00000000";      // obtiene el hijo der
            modifyLastTreeRegistry(cantRegistros, fatherPosition);   // cambia datos del registro padre
            unsigned short padre = (cantRegistros / 2);
            std::string parent = _conversion->decimalToBinary(std::to_string(padre));
            dataBinaryRecord = (parent + leftChild + rightChild);
        }
        dataBinaryRecord += getUserRecordData(pListPtr);

        cout << "El BINARIO es-->: " << dataBinaryRecord << endl;
        cout << "El tamano BINARIO es-->: " << dataBinaryRecord.length() << endl;
        //        cout << "tamanoRegistro " << _metadataPtr->getRecordSize() << endl;

        this->_disk->write(this->_metadataPtr->getEOF() ,
                           _conversion->fromStringToConstChar(dataBinaryRecord));  // en vez de cero sería en EOF
        //  Actualiza el tamaño de EOF y la cantidad de registros insertados
        this->_metadataPtr->setEOF(this->_metadataPtr->getEOF() + tamanoRegistro);
        //cout << "EOF  " << this->_metadataPtr->getEOF()  << endl;
        //        cout << "BOF  " << this->_metadataPtr->getFirstRecordPos()  << endl;
        this->_metadataPtr->setNumberOfRecords(++cantRegistros);
    } else {
        cout << "$$$$$$$$$$ Insertando en espacio... $$$$$$$$$$" << endl;
        aux_InsertRecord2Disk(pListPtr);
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << "$$$$$$$$$$ Escritura a disco finalizada $$$$$$$$$$" << endl;
    cout << "-----------------------------------------------------------------" << endl;
//    }// fin del else de computeMaxSizeOfRegistryInBlock()
}

/**
 * @brief BTRecordFile::insertRecordAUX
 * @param pNewRecord
 * @param pHDer
 * Función auxiliar que inserta registros en los espacios que han sido borrados
 */
void BTRecordFile::aux_InsertRecord2Disk(DLL<IRecordDataType *> *pListPtr)
{
    unsigned short hIzq;
    unsigned short recordSize = this->_metadataPtr->getRecordSize();
    unsigned short BOF = this->_metadataPtr->getFirstRecordPos();
    cout << "--------------------------" << endl;
    cout << "ListFreeBlocks Antes " << this->_metadataPtr->getFreeBlockList() << endl;
    unsigned short tmp = this->_metadataPtr->getFreeBlockList();
    this->_metadataPtr->setFreeBlockList(getLeftChildErase(tmp));
    cout << "ListFreeBlocks Después " << this->_metadataPtr->getFreeBlockList() << endl;
    cout << "--------------------------" << endl;
    unsigned short path2Write = BOF + (recordSize * (tmp - 1));
    unsigned short dato = (tmp / 2);
    std::string datoStr = _conversion->fromShort2String(dato);
    std::string datoStrBinary = _conversion->decimalToBinary(datoStr);
    this->_disk->write(path2Write, _conversion->fromStringToConstChar(datoStrBinary));     //setea el padre
    cout << "El padre es ......... " << this->_disk->read(path2Write, 7) << endl;

    const char* hDer = this->_disk->read(path2Write + 16, 7);   //se obtiene el hDer para calcular el hIzq
    std::string hDerString = _conversion->fromConstChar2String(hDer);
    cout << "El hder será ......... " << hDerString << endl;
    std::string hDerStringDecimal = _conversion->binaryToDecimal(hDerString);

    if (hDerString.compare("00000000")) {   // TIENE HIJO DERECHO!!!!
        hIzq = _conversion->fromString2Short(hDerStringDecimal) - 1;  // se obtiene hIzq del registro
    } else { // HIJO DERECHO ES 0, NO TIENE HIJO DERECHO!!!
        hIzq = tmp * 2;// se obtiene hIzq del registro
    }
    cout << "El hIzq será ......... " << hIzq << endl;
    std::string hIzqString = _conversion->fromShort2String(hIzq);
    std::string hIzqStringBinary = _conversion->decimalToBinary(hIzqString);
    this->_disk->write(path2Write + 8, _conversion->fromStringToConstChar(hIzqStringBinary));
    std::string dataBinaryRecord;  // concatenacion del registro a binario
    dataBinaryRecord += getUserRecordData(pListPtr);
    this->_disk->write(path2Write + 24 ,
                       _conversion->fromStringToConstChar(dataBinaryRecord));  // en vez de cero sería en EOF

    cout << "......... Registro insertado ........." << endl;
}

/**
 * @brief BTRecordFile::getUserRecordData
 * Itera sobre la DLL de los datos que el usuario introduce
 */
std::string BTRecordFile::getUserRecordData(DLL<IRecordDataType *> *_dataListPtr)
{
    std::string finalBinaryRecord;  // concatenacion del registro
    DLLNode<IRecordDataType*> *tmp = _dataListPtr->getHeadPtr();
    RecordDataType<std::string> *data;
    while (tmp != nullptr) {
        data = dynamic_cast<RecordDataType<std::string>*>(tmp->getData());
        QString qstrData = _conversion->fromStringToQString(*data->getDataPtr());

        if (_conversion->verificaValidezDouble(qstrData) == true) {                    // VERIFICACION DE SI EL DATO ES DEL TIPO DOUBLE
            _conversion->setFillData((data->getSize() * 8));
            finalBinaryRecord += _conversion->fromDoubleString2BinaryString(*data->getDataPtr());
        }

        else if (_conversion->verificaValidezInt(qstrData) == true) {   // cadena no de numeros
            _conversion->setFillData((data->getSize() * 8));
            finalBinaryRecord += _conversion->decimalToBinary(*data->getDataPtr());
        } else { // letras
            _conversion->setFillData((data->getSize() * 8));
            finalBinaryRecord += _conversion->stringToBinary(*data->getDataPtr());
        }
        tmp = tmp->getNextPtr();
    }
    cout << "El registro en BINARIO es: " << "\n" << finalBinaryRecord << endl;
    _conversion->setFillData(8);
    return finalBinaryRecord;
}

/**
 * @brief BTRecordFile::modifyLastTreeRegistry
 * modifica el padre y los hijos del regsitro anterior para construir el arbol
 * de informacion
 * @param pRecordNumber;# numero de registro que sirve para actualizar los datos
 * del Arbol de Registros (cambia padres e hijos) de registros anteriores
 * @param
 */
void BTRecordFile::modifyLastTreeRegistry(unsigned short pRecordNumber,
        unsigned short pChangePositon)
{
    std::string modifiedChild = _conversion->decimalToBinary(std::to_string(pRecordNumber));
    const char *modifiedChildChar = modifiedChild.c_str();
    if (pRecordNumber % 2 == 0) {   // registro es par modifica hizq
        this->_disk->write(pChangePositon + 8, modifiedChildChar);
    } else {    // registro es impar modifica hder
        this->_disk->write(pChangePositon + 16, modifiedChildChar);
    }
}

void BTRecordFile::deleteRecordFromDisk(unsigned short recordID)
{
    unsigned short BOF = this->_metadataPtr->getFirstRecordPos();
    unsigned short recordSize = this->_metadataPtr->getRecordSize();
    unsigned short ListFreeBlocks = this->_metadataPtr->getFreeBlockList();
    // formula para detectar el lugar del registro por borrar
    unsigned short erasedRecordSpace = BOF + (recordSize * (recordID - 1));
    cout << "--------------------------" << endl;
    cout << "Borrando el registro # " << recordID << endl;
    cout << "--------------------------" << endl;

    if (ListFreeBlocks == 0) {  // no bloques libres no hay ninguno borrado
        this->_metadataPtr->setFreeBlockList(recordID);
        this->_disk->write(erasedRecordSpace, "00000000");  // setea el padre
        this->_disk->write(erasedRecordSpace + 8, "00000000");  // setea el hizq
    } else if (ListFreeBlocks != 0) { // no existe ningún registro borrado
        // setea el hijo izq del dato de _listFreeBlocks
        unsigned short actual = ListFreeBlocks;
        getLeftChildErase(actual);
        while (getLeftChildErase(actual) != 0) {
            actual = getLeftChildErase(actual);
        }
        std::string stringID = _conversion->fromShort2String(recordID);
        std::string datoBorrado = _conversion->decimalToBinary(stringID);
        unsigned short erasedRecordSpace1 = BOF + (recordSize * (actual - 1));

        this->_disk->write(erasedRecordSpace1 + 8, _conversion->fromStringToConstChar(datoBorrado));    // setea el padre a 0
        this->_disk->write(erasedRecordSpace, "00000000");          // setea el padre a 0
        this->_disk->write(erasedRecordSpace + 8, "00000000");      // setea hIZQ a 0
    } else {
        cout << "No existe registro para borrar o.O" << endl;
    }
}

/**
 * @brief BTRecordFile::getLeftChildErase
 * @param pNextLeftChild
 * @return
 * Devuelve la proxima posición de el hijo izquierdo que ha sido borrado
 */
unsigned short BTRecordFile::getLeftChildErase(unsigned short pNextLeftChild)
{
    unsigned short BOF = this->_metadataPtr->getFirstRecordPos();
    unsigned short recordSize = this->_metadataPtr->getRecordSize();
    // se obtiene al hijo IZQ del dato borrado
    unsigned short erasedRecordSpace = BOF + (recordSize * (pNextLeftChild - 1));
    // conversion de const char* a std::string
    std::string nextLeftPosition = _conversion->fromConstChar2String(
                                       this->_disk->read(erasedRecordSpace + 8, 7));
    // conversion de std::string binario a std::string decimal
    std::string nextLeftPositionDECIMAL = this->_conversion->binaryToDecimal(nextLeftPosition);
    // conversion de std::string a unsigned short
    unsigned short shortNumber = _conversion->fromString2Short(nextLeftPositionDECIMAL);
    cout << "Proximo registro borrado--->" << shortNumber << endl;
    return shortNumber;
}

/**
 * @brief BTRecordFile::readALLRecordsFromDisk
 * Lee los datos qque están en el disco para presentarlos en pantalla
 */
void BTRecordFile::readALLRecordsFromDisk()
{
    int contador = 1;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "$$$$$$$$$$ Lectura de disco $$$$$$$$$$" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    while (contador <= _metadataPtr->getEOF()) {
        //cout << "EOF" << _metadataPtr->getEOF()<< endl;
        readOneRecordFromDisk(contador);
        ++contador;
    }
}

/**
 * @brief BTRecordFile::readOneRecordFromDisk
 * @param recordID
 * Lee solo un registro desde disco
 */
void BTRecordFile::readOneRecordFromDisk(unsigned short recordID)
{
    if (recordID <= this->_metadataPtr->getNumberOfRecords() - 1) {
        unsigned short BOF = this->_metadataPtr->getFirstRecordPos();
        unsigned short recordSize = this->_metadataPtr->getRecordSize();
        unsigned short recordSpace = BOF + (recordSize * (recordID - 1));
        const char* padre = this->_disk->read(recordSpace, 7);
        std::string stringData1 = _conversion->fromConstChar2String(padre);
        const char* Hizq = this->_disk->read(recordSpace + 8, 7);
        std::string stringData2 = _conversion->fromConstChar2String(Hizq);
        const char* Hder = this->_disk->read(recordSpace + 16, 7);
        std::string stringData3 = _conversion->fromConstChar2String(Hder);

        cout << "BOF: " << BOF << "EOF: " << _metadataPtr->getEOF() << "\nrecordSize: " << recordSize << "\nrecordSpace: " << recordSpace;

        cout << "Registro #" << recordID << " " ;
        cout << "Padre: ";
        cout << _conversion->binaryToDecimal(stringData1);
        cout << " hIzq: ";
        cout << _conversion->binaryToDecimal(stringData2);
        cout << " hDer: ";
        cout << _conversion->binaryToDecimal(stringData3);
        cout << endl;

        DLL<IRecordDataType*> *tmp1 = _metadataPtr->getRecordStruct();
        DLLNode<IRecordDataType*> *tmp = tmp1->getHeadPtr();
        const char *data;
        recordSpace += 24;
        while (tmp != nullptr) {
            cout << " " << tmp->getData()->getName() << ": " ;
            data = (dynamic_cast<RecordDataType<char>*>(tmp->getData()))->getDataPtr();
            const char *DATO = _disk->read(recordSpace, tmp->getData()->getSize() * 8 - 1);
            std::string DATOSTR(DATO);
            cout << sortUserDataFromDisk(DATOSTR, *data);
            recordSpace += (tmp->getData()->getSize() * 8);
            tmp = tmp->getNextPtr();
        }
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
    }
}

/**
 * @brief BTRecordFile::saveMetadata2Disk
 * Guarda los metadatos antes de cerrar sesión y los escribirá en disco
 */
void BTRecordFile::saveMetadata2Disk()
{
    std::string metadataBinary;
    std::string puntero = _conversion->fromShort2String(_metadataPtr->getPointerNextBlock());
    std::string tamanoRegistro = _conversion->fromShort2String(_metadataPtr->getRecordSize());
    std::string BOF = _conversion->fromShort2String(_metadataPtr->getFirstRecordPos());
    std::string cantidadRegistro = _conversion->fromShort2String(_metadataPtr->getNumberOfRecords());
    std::string ENDOF = _conversion->fromShort2String(_metadataPtr->getEOF());
    std::string freeBlocks = _conversion->fromShort2String(_metadataPtr->getFreeBlockList());
    _conversion->setFillData(16);   // hace los datos de tamaño 16 en binario
    metadataBinary += _conversion->decimalToBinary(puntero);
    cout << _conversion->decimalToBinary(puntero) << endl;
    metadataBinary += _conversion->decimalToBinary(tamanoRegistro);
    cout << _conversion->decimalToBinary(tamanoRegistro) << endl;
    metadataBinary += _conversion->decimalToBinary(BOF);
    cout << _conversion->decimalToBinary(BOF) << endl;
    metadataBinary += _conversion->decimalToBinary(cantidadRegistro);
    cout << _conversion->decimalToBinary(cantidadRegistro) << endl;
    metadataBinary += _conversion->decimalToBinary(ENDOF);
    cout << _conversion->decimalToBinary(ENDOF) << endl;
    metadataBinary += _conversion->decimalToBinary(freeBlocks);
    cout << _conversion->decimalToBinary(freeBlocks) << endl;
    cout << "Metadatos: " << metadataBinary << endl;
    cout << "Tamaño Metadatos: " << metadataBinary.length() << endl;

    DLL<IRecordDataType*> *tmp1 = _metadataPtr->getRecordStruct();
    DLLNode<IRecordDataType*> *tmp = tmp1->getHeadPtr();
    std::string size = _conversion->fromShort2String(tmp1->getSize());  // numero de datos de usuario
    metadataBinary += _conversion->decimalToBinary(size);  // cantidad de datos usuario

    _conversion->setFillData(_sizeOwner_FileName);  //24
    metadataBinary += _conversion->stringToBinary(_metadataPtr->getFileName());
    cout << _conversion->stringToBinary(_metadataPtr->getFileName()) << endl;
    metadataBinary += _conversion->stringToBinary(_metadataPtr->getOwner());
    cout << _conversion->stringToBinary(_metadataPtr->getOwner()) << endl;

    cout << "Metadatos: " << metadataBinary << endl;
    cout << "Tamaño Metadatos: " << metadataBinary.length() << endl;
    unsigned short data1;
    std::string data2;
    std::string data3;
    std::string datos;
    while (tmp != nullptr) {
        data1 = (dynamic_cast<RecordDataType<char>*>(tmp->getData()))->getSize();
        data2 = (dynamic_cast<RecordDataType<char>*>(tmp->getData()))->getDataPtr();
        data3 = (dynamic_cast<RecordDataType<char>*>(tmp->getData()))->getName(); // titulo
        std::string tamanoDato = _conversion->fromShort2String(data1);
        _conversion->setFillData(_sizeOwner_FileName);  //24
        datos += _conversion->decimalToBinary(tamanoDato);
        datos += _conversion->decimalToBinary(data2);
        datos += _conversion->stringToBinary(data3);
        cout << "MUSR1: " << data1 << " " << _conversion->decimalToBinary(tamanoDato) << endl;
        cout << "MUSR2: " << data2 << " " << _conversion->decimalToBinary(data2) << endl;
        cout << "MUSR3: " << data3 << " " << _conversion->stringToBinary(data3) << endl;
        cout << "MetadatosUSR: " << datos << endl;
        cout << "Tamaño MetadatosUSR: " << datos.length() << endl;
        tmp = tmp->getNextPtr();
    }
    metadataBinary += datos;
    cout << "Metadatos: " << metadataBinary << endl;
    cout << "Tamaño Metadatos: " << metadataBinary.length() << endl;

    _disk->write(0, _conversion->fromStringToConstChar(metadataBinary));    // escribe a disco
  //    return metadataBinary;
}

void BTRecordFile::loadMetadata()
{
    std::string *DatosUsuario = new std::string[7];
    DLL<IRecordDataType*> *tmp1 = new DLL<IRecordDataType*>();
    int contador = 0;
    const char* data;
    std::string strData;
    while( contador != 112 ){
        data = _disk->read( contador, 15 );
        strData = _conversion->fromConstChar2String( data );
        cout << "-->"<<_conversion->binaryToDecimal( strData ) <<  endl;
        DatosUsuario[contador/16] = strData;
        contador += 16;
    }
    cout << endl;

    while ( contador != (144 + 16) ){// lectura del Owner nombreArchivo (tamaño 24)
        data = _disk->read( contador, _sizeOwner_FileName - 1 );
        strData = _conversion->fromConstChar2String( data );
        cout << "-->"<<_conversion->binaryToString( strData ) <<  endl;
        contador += _sizeOwner_FileName;
    }
    const char* data0;
    const char* data1;
    const char* data2;
    unsigned short contador2 = 0;
    std::string p = _conversion->binaryToDecimal( DatosUsuario[6] );
    _conversion->fromString2Short( p );
    while( contador2 != _conversion->fromString2Short(p) ){
        //lectura del titulo de dato
        data0 =  _diskMetadata->read( contador, 23 );                                  // lectura del tipo de dato
        data1 =  _diskMetadata->read( contador + 24 , 23 );                            // lectura del tamaño de dato
        data2 =  _diskMetadata->read( contador + 48, 23 );    // lectura del titulo de dato
        loadUserInfo( tmp1, data0, data1, data2 );
        contador2++;
        contador += (_sizeOwner_FileName * 3);
        cout << "data0: " << data0 << endl;
        cout << "data1: " << data1  << endl;
        cout << "data2: " << data2  << endl;
    }

    dataClassification(DatosUsuario);
}

/**
 * @brief BTRecordFile::dataClassification
 * @param pDatosUsuario
 * Clasificación de metadatos, se setean datos
 */
void BTRecordFile::dataClassification(std::string *pDatosUsuario)
{
    std::string puntero = _conversion->binaryToDecimal(pDatosUsuario[0]);
    unsigned short numero00 = _conversion->fromString2Short(puntero);
    _metadataPtr->setPointerNextBlock(numero00);

    std::string tamanoRegistro = _conversion->binaryToDecimal(pDatosUsuario[1]);
    unsigned short numero0 = _conversion->fromString2Short(tamanoRegistro);
    _metadataPtr->setRecordSize(numero0);

    std::string BOF = _conversion->binaryToDecimal(pDatosUsuario[2]);
    unsigned short numero1 = _conversion->fromString2Short(BOF);
    _metadataPtr->setFirstRecordPos(numero1);

    std::string cantidadRegistro = _conversion->binaryToDecimal(pDatosUsuario[3]);
    unsigned short numero2 = _conversion->fromString2Short(cantidadRegistro);
    _metadataPtr->setNumberOfRecords(numero2);

    std::string pEOF = _conversion->binaryToDecimal(pDatosUsuario[4]);
    unsigned short numero3 = _conversion->fromString2Short(pEOF);
    _metadataPtr->setEOF(numero3);

    std::string freeBlocks = _conversion->binaryToDecimal(pDatosUsuario[5]);
    unsigned short numero4 = _conversion->fromString2Short(freeBlocks);
    _metadataPtr->setFreeBlockList(numero4);

    std::string userdataLength = _conversion->binaryToDecimal(pDatosUsuario[6]);
    unsigned short numero5 = _conversion->fromString2Short(userdataLength);
    this->_cantidadDatosUser = numero5;
}

/**
 * @brief BTRecordFile::loadUserInfo
 * @param pTmp1
 * @param pTipo
 * @param pTamano
 * @param pTitulo
 * Clasificación de los datos de usuario se guardan datos
 */
void BTRecordFile::loadUserInfo(DLL<IRecordDataType*> *pTmp1, std::string pTipo,
                                std::string pTamano, std::string pTitulo)
{
    std::string  tipo = _conversion->binaryToDecimal(pTipo);
    std::string  titulo = _conversion->binaryToString(pTitulo);
    char p = tipo[1];
    unsigned short size = _conversion->fromString2Short(pTamano);
    RecordDataType<char> *tmp = new RecordDataType<char>(titulo , p , size);
    pTmp1->insertAtBack(tmp);
}


/**
 * @brief BTRecordFile::sortUserDataFromDisk
 * @param pData
 * @param pConversion
 * @param pTipo
 * @return std::string finalBinaryRecord
 * Clasifica los tipos de datos para poder ser leídos desde disco y casteados
 * de buena manera
 */
std::string BTRecordFile::sortUserDataFromDisk(std::string pData, char pTipo)
{
    std::string finalBinaryRecord;
    if (pTipo == BTRecordFileMetadata::DOUBLE) { // Double
        finalBinaryRecord = _conversion->fromBinaryString2DoubleString(pData);    // CONVERSION DE BINARIO A DOUBLE
    } else if (pTipo == BTRecordFileMetadata::INT) { // INT
        finalBinaryRecord = _conversion->binaryToDecimal(pData);
    } else if (pTipo == BTRecordFileMetadata::STRING ||
               pTipo == BTRecordFileMetadata::CHAR) { // string o char
        finalBinaryRecord = _conversion->binaryToString(pData);
    } else { // son solo numeros

    }
    return finalBinaryRecord;   // retorna conversion a decimal
}

//------------------------------------------------------------------------------
//   FIN INSERCION, LECTURA Y BORRADO DE DATOS EN DISCO
//------------------------------------------------------------------------------

/**
 * @brief BTRecordFile::insertRecord
 * @param pListPtr
 * @return newRecord, nuevo registro insertado
 * Función para insertar registros en la RAM
 */
BTRecord *BTRecordFile::insertRecord(DLL<IRecordDataType *> *pListPtr)
{
    std::cout << "------------------------------------------------------------"
              "\nMetadatos inicio: \n";
    getMetadata()->printMetadata();
    std::cout << "------------------------------------------------------------\n\n";
    unsigned short cantRegistros = this->_metadataPtr->getNumberOfRecords();
    unsigned short tamanoRegistro = this->_metadataPtr->getRecordSize();
    unsigned short posicionPrimerRegistro = this->_metadataPtr->getFirstRecordPos();
    std::string dataBinaryRecord;  // concatenacion del registro a binario
    cout << "cantRegistros: " << cantRegistros << endl;
    cout << "tamanoRegistro: " << tamanoRegistro << endl;
    cout << "BOF: " << posicionPrimerRegistro << endl;
    cout << "EOF: " << _metadataPtr->getEOF() << endl;

    if (this->_metadataPtr->getFreeBlockList() == 0) {
        if (cantRegistros == 1) {
            dataBinaryRecord  = "000000000000000000000000"; // No tiene ni padre ni hijos
        } else { // se insertan otros registros después de haber uno
            cout << "CANTIDAD DE REGISTROS--> " << cantRegistros << endl;
            unsigned short fatherPosition = posicionPrimerRegistro +
                                            ((tamanoRegistro) * ((cantRegistros / 2) - 1));
            std::string leftChild = "00000000";       // obtiene el hijo izq
            std::string rightChild = "00000000";      // obtiene el hijo der
            modifyLastTreeRegistry(cantRegistros, fatherPosition);   // cambia datos del registro padre
            unsigned short padre = (cantRegistros / 2);
            std::string parent = _conversion->decimalToBinary(std::to_string(padre));
            dataBinaryRecord = (parent + leftChild + rightChild);
        }
        dataBinaryRecord += getUserRecordData(pListPtr);
        cout << "El BINARIO es-->: " << dataBinaryRecord << endl;
        //        cout << "El tamano BINARIO es-->: " << dataBinaryRecord.length() << endl;
        //        cout << "tamanoRegistro " << _metadataPtr->getRecordSize() << endl;
        std::cout << "???????????????????????????????????????????????\n";
        std::cout << "Dirección de inserción: \n";
        std::cout << "eof: " << _metadataPtr->getEOF();

        this->_disk->write(this->_metadataPtr->getEOF() ,
                           _conversion->fromStringToConstChar(dataBinaryRecord));  // en vez de cero sería en EOF
        std::cout << "\n???????????????????????????????????????????????\n";

        //  Actualiza el tamaño de EOF y la cantidad de registros insertados
        this->_metadataPtr->setEOF(this->_metadataPtr->getEOF() + tamanoRegistro);
        //cout << "EOF  " << this->_metadataPtr->getEOF()  << endl;
        //        cout << "BOF  " << this->_metadataPtr->getFirstRecordPos()  << endl;
        this->_metadataPtr->setNumberOfRecords(++cantRegistros);
    } else {
        cout << "$$$$$$$$$$ Insertando en espacio... $$$$$$$$$$" << endl;
        aux_InsertRecord2Disk(pListPtr);
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << "$$$$$$$$$$ Escritura a disco finalizada $$$$$$$$$$" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    std::cout << "\n\n------------------------------------------------------------"
              "\nMetadatos final: \n";
    getMetadata()->printMetadata();
    std::cout << "------------------------------------------------------------\n\n";

}

/**
 * @brief BTRecordFile::insertRecordAUX
 * @param pNewRecord
 * @param pHDer
 * Función auxiliar que inserta registros en los espacios que han sido borrados
 */
void BTRecordFile::insertRecordAUX(BTRecord *pNewRecord, unsigned short pHDer)
{
    cout << "--------------------------" << endl;
    cout << "ListFreeBlocks Antes " << this->getListFreeBlocks() << endl;
    unsigned short tmp = this->getListFreeBlocks();
    this->setListFreeBlocks(this->_registryArray[tmp].getLeftChildPtr());
    cout << "ListFreeBlocks Después " << this->getListFreeBlocks() << endl;
    cout << "--------------------------" << endl;
    this->_registryArray[tmp] = *pNewRecord;
    pNewRecord->setParentPtr(tmp / 2);      // setea el padre
    (this->_registryArray[tmp]).setParentPtr(tmp / 2);

    pNewRecord->setRightChildPtr(pHDer);
    (this->_registryArray[tmp])
    .setRightChildPtr(pHDer);

    pNewRecord->setLeftChildPtr(this->_registryArray[tmp].getRightChildPtr() - 1);
    (this->_registryArray[tmp])
    .setLeftChildPtr(this->_registryArray[tmp].getRightChildPtr() - 1);
}


/**
 * @brief BTRecordFile::readRecordFromDiskTest
 * @param pDisk
 * @param pRecordID
 * Hace la lectura de un registro en la RAM
 */
void BTRecordFile::readRecordFromDiskTest(Disk pDisk, unsigned short pRecordID)
{
    const char *padre = pDisk.read(this->_metadataPtr->getFirstRecordPos(), 7);
    const char *hizq = pDisk.read(this->_metadataPtr->getFirstRecordPos() + 8, 7);
    const char *hder = pDisk.read(this->_metadataPtr->getFirstRecordPos() + 16, 7);
    std::string father(padre);          // obtiene el padre
    std::string HI(hizq);               // obtiene el hijo izq
    std::string HD(hder);               // obtiene el hijo der
    unsigned short _sizeCounter = this->_metadataPtr->getFirstRecordPos() + 24;       // inicio de la data
    DLL<IRecordDataType*> *tmp1 = _metadataPtr->getRecordStruct();
    DLLNode<IRecordDataType*> *tmp = tmp1->getHeadPtr();
    const char *data;

    cout << "Binario " << father << " " << HI << " " << HD << endl;
    std::string P = _conversion->binaryToDecimal(father);
    std::string PHI = _conversion->binaryToDecimal(HI);
    std::string PHD = _conversion->binaryToDecimal(HD);
    cout << P << " " << PHI << " " << PHD << " ";
    while (tmp != nullptr) {
        data = (dynamic_cast<RecordDataType<char>*>(tmp->getData()))->getDataPtr();
        const char *DATO = pDisk.read(_sizeCounter, 7);
        std::string DATOSTR(DATO);       // obtiene el padre
        _sizeCounter += 8;
        cout << sortUserDataFromDisk(DATOSTR, *data) << endl;
        tmp = tmp->getNextPtr();
    }
}


/**
 * @brief printDataStructureByUser imprime cómo está conformado el registro
 * según los campos que ingresó el usuario
 */
void BTRecordFile::printDataStructureByUser() // TODO ver que hay duplicado
{
    std::cout << "Los registros tienen la siguiente estructura: \n\n";

    DLLNode<IRecordDataType *> *current =
        _metadataPtr->getRecordStruct()->getHeadPtr();

    char headerName;

    do {
        headerName = *current->getData()->getName().c_str();

        if (headerName == BTRecordFileMetadata::STRING) {
            std::cout << "string";
        } else if (headerName == BTRecordFileMetadata::CHAR) {
            std::cout << "char";
        } else if (headerName == BTRecordFileMetadata::SHORT) {
            std::cout << "short";
        } else if (headerName == BTRecordFileMetadata::INT) {
            std::cout << "int";
        } else if (headerName == BTRecordFileMetadata::DOUBLE) {
            std::cout << "double";
        } else if (headerName == BTRecordFileMetadata::BOOL) {
            std::cout << "bool";
        } else {
            std::cout << "El tipo de dato no es soportado";
        }

        //        current = current->getNextPtr();
        current++;

    } while (current != nullptr);

    std::cout << "\n\n";
}

/**
 * @brief BTRecordFile::deleteRecord
 * @param pDatoBorrado
 * @return
 * hace un borrado de un registro y "crea" una lista de espacios vacíos para ser
 * ocupados después por otros nuevos registros
 */
BTRecord *BTRecordFile::deleteRecord(unsigned short recordID)
{
    unsigned short BOF = this->_metadataPtr->getFirstRecordPos();
    unsigned short recordSize = this->_metadataPtr->getRecordSize();
    unsigned short ListFreeBlocks = this->_metadataPtr->getFreeBlockList();
    // formula para detectar el lugar del registro por borrar
    unsigned short erasedRecordSpace = BOF + (recordSize * (recordID - 1));
    cout << "--------------------------" << endl;
    cout << "Borrando el registro # " << recordID << endl;
    cout << "--------------------------" << endl;

    if (ListFreeBlocks == 0) {  // no bloques libres no hay ninguno borrado
        this->_metadataPtr->setFreeBlockList(recordID);
        this->_disk->write(erasedRecordSpace, "00000000");  // setea el padre
        this->_disk->write(erasedRecordSpace + 8, "00000000");  // setea el hizq
    } else if (ListFreeBlocks != 0) { // no existe ningún registro borrado
        // setea el hijo izq del dato de _listFreeBlocks
        unsigned short actual = ListFreeBlocks;
        getLeftChildErase(actual);
        while (getLeftChildErase(actual) != 0) {
            actual = getLeftChildErase(actual);
        }
        std::string stringID = _conversion->fromShort2String(recordID);
        std::string datoBorrado = _conversion->decimalToBinary(stringID);
        unsigned short erasedRecordSpace1 = BOF + (recordSize * (actual - 1));

        this->_disk->write(erasedRecordSpace1 + 8, _conversion->fromStringToConstChar(datoBorrado));    // setea el padre a 0
        this->_disk->write(erasedRecordSpace, "00000000");          // setea el padre a 0
        this->_disk->write(erasedRecordSpace + 8, "00000000");      // setea hIZQ a 0
    } else {
        cout << "No existe registro para borrar o.O" << endl;
    }
}

int BTRecordFile::getCounter() const
{
    return _counter;
}

void BTRecordFile::setCounter(int counter)
{
    _counter = counter;
}

unsigned short BTRecordFile::getListFreeBlocks() const
{
    return _listFreeBlocks;
}

void BTRecordFile::setListFreeBlocks(unsigned short pListFreeBlocks)
{
    this->_listFreeBlocks = pListFreeBlocks;
}

BTRecordFile::~BTRecordFile()
{
    delete []_registryArray;    // se borra el arreglo de registros
}

unsigned short BTRecordFile::showFragmentation() const
{
    return 0; // TODO
}

bool BTRecordFile::defragFile()
{
    return false; // TODO
}

