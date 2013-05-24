/*******************************************************************************
 * File: BTRecordFile.cpp
 * Author: Brallan Aguilar y Daniel Araya
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include <iomanip>
#include "BTRecordFile.h"

BTRecordFile::BTRecordFile()
{
}

BTRecordFile::BTRecordFile(BTRecordFileMetadata *pMetadata)
    : _metadataPtr(pMetadata)
{
    this->_registryArray = new BTRecord[100];
    this->_counter = 1;
    this->_listFreeBlocks = 0; // lista de bloques libres está vacía
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

/**
 * @brief BTRecordFile::insertRecord
 * @param pListPtr
 * @return newRecord, nuevo registro insertado
 * Función para insertar registros en la RAM
 */
BTRecord *BTRecordFile::insertRecord(DLL<IRecordDataType *> *pListPtr)
{
    unsigned short hDer = this->_registryArray[3].getRightChildPtr();
    BTRecord *newRecord = new BTRecord();
    newRecord->setDataList(pListPtr);
    if (this->getListFreeBlocks() == 0) {
        if (this->_registryArray == NULL) {   //arreglo vacío
            newRecord->setParentPtr(0);
            newRecord->setLeftChildPtr(0);
            newRecord->setRightChildPtr(0);
            this->_registryArray[1] = *newRecord;    // inicio en la posición 1
        } else {
            this->_registryArray[_counter] = *newRecord;
            newRecord->setParentPtr(_counter / 2);      // setea el padre
            (this->_registryArray[_counter]).setParentPtr(_counter / 2);
            if ((_counter % 2) == 0) {    //si el numero es par es hijo izquierdo
                newRecord->setLeftChildPtr(0);      // no tiene hijos
                newRecord->setRightChildPtr(0);     // no tiene hijos
                (this->_registryArray[newRecord->getParentPtr()])
                .setLeftChildPtr(_counter);
            } else {
                newRecord->setRightChildPtr(0);     // no tiene hijos
                newRecord->setLeftChildPtr(0);      // no tiene hijos
                (this->_registryArray[newRecord->getParentPtr()])
                .setRightChildPtr(_counter);
            }
        }
        this->_counter++;   // aumenta la posición para insertar el siguiente dato
    } else {
        insertRecordAUX(newRecord, hDer);
    }
    return newRecord;
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


//------------------------------------------------------------------------------
//   INSERCION DE DATOS EN DISCO
//------------------------------------------------------------------------------
/**
 * @brief BTRecordFile::insertRecord2Disk
 * @param pListPtr
 * Función que se encargará de insertar los registros al disco
 */
void BTRecordFile::insertRecord2Disk( DLL<IRecordDataType *> *pListPtr ){
    unsigned short cantRegistros = this->_metadataPtr->getNumberOfRecords();
    unsigned short tamanoRegistro = this->_metadataPtr->getRecordSize();
    unsigned short posicionPrimerRegistro = this->_metadataPtr->getFirstRecordPos();
    std::string dataBinaryRecord;  // concatenacion del registro a binario
    if( this->_disk == NULL ){
        this->_disk = new Disk( 1,7 );
        dataBinaryRecord  = "000000000000000000000000"; // No tiene ni padre ni hijos
    }
    else{ // se insertan otros registros después de haber uno
        cout << "CANTIDAD DE REGISTROS--> " << cantRegistros << endl;
        unsigned short fatherPosition = posicionPrimerRegistro +
                ( (tamanoRegistro) * ( ( cantRegistros / 2) - 1) );
        std::string leftChild = "00000000";       // obtiene el hijo izq
        std::string rightChild = "00000000";      // obtiene el hijo der
        modifyLastTreeRegistry( cantRegistros, fatherPosition ); // cambia datos del registro padre
        unsigned short padre = cantRegistros / 2;
        std::string parent = _conversion->decimalToBinary( std::to_string(padre) );
        dataBinaryRecord += ( parent + leftChild + rightChild );
    }
    dataBinaryRecord += getUserRecordData( pListPtr );
    //const char* buffer = dataBinaryRecord.c_str();
    cout << "El BINARIO es-->: " << dataBinaryRecord << endl;
    this->_disk->write( this->_metadataPtr->getEOF() , _conversion->fromStringToConstChar(dataBinaryRecord) ); // en vez de cero sería en EOF
    cout << "-----------------------------------------------------------------" << endl;
    cout << "$$$$$$$$$$ Escritura a disco finalizada $$$$$$$$$$" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    //  Actualiza el tamaño de EOF y la cantidad de registros insertados
    this->_metadataPtr->setEOF( this->_metadataPtr->getEOF() + tamanoRegistro );
    this->_metadataPtr->setNumberOfRecords( ++cantRegistros );
}

/**
 * @brief BTRecordFile::getUserRecordData
 * Itera sobre la DLL de los datos que el usuario introduce
 */
std::string BTRecordFile::getUserRecordData( DLL<IRecordDataType *> *_dataListPtr ){
    std::string finalBinaryRecord;  // concatenacion del registro
    DLLNode<IRecordDataType*> *tmp = _dataListPtr->getHeadPtr();
    RecordDataType<std::string> *data;
    while( tmp != nullptr ){
        data = dynamic_cast<RecordDataType<std::string>*>(tmp->getData());
        QString qstrData= _conversion->fromStringToQString(*data->getDataPtr());
//        std::string str( *data->getDataPtr() ); // Convert from std::string 2 Qstring
//        QString qstrData(str.c_str()); // donde qstr es el QString
       if ( !_conversion->verificaValidezInt( qstrData ) ){ // cadena no de numeros
            finalBinaryRecord += _conversion->stringToBinary( *data->getDataPtr() );
        }
        else{   // son solo numeros
            finalBinaryRecord += _conversion->decimalToBinary( *data->getDataPtr() );
        }
        tmp = tmp->getNextPtr();
    }
    cout << "El registro en BINARIO es: " << "\n" << finalBinaryRecord << endl;
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
                 unsigned short pChangePositon){
    std::string modifiedChild = _conversion->decimalToBinary( std::to_string(pRecordNumber) );
    const char *modifiedChildChar = modifiedChild.c_str();
    if (pRecordNumber % 2 == 0){    // registro es par modifica hizq
        this->_disk->write( pChangePositon + 8, modifiedChildChar );
    }
    else{       // registro es impar modifica hder
        this->_disk->write( pChangePositon + 16, modifiedChildChar );
    }
}

void BTRecordFile::deleteRecordFromDisk( unsigned short recordID ){
    unsigned short BOF = this->_metadataPtr->getEOF();
    unsigned short recordSize = this->_metadataPtr->getNumberOfRecords();
    unsigned short ListFreeBlocks = this->_metadataPtr->getFreeBlockList();
    // formula para detectar el lugar del registro por borrar
    unsigned short erasedRecordSpace = BOF + ( recordSize * (recordID - 1) );
    cout << "--------------------------" << endl;
    cout << "Borrando el registro # " << recordID << endl;
    cout << "--------------------------" << endl;

    if( ListFreeBlocks == 0 ){  // no bloques libres no hay ninguno borrado
        this->_metadataPtr->setFreeBlockList( recordID );
        this->_disk->write(erasedRecordSpace, "00000000");  // setea el padre
        this->_disk->write(erasedRecordSpace + 8, "00000000");  // setea el hizq
    }
    else if( ListFreeBlocks != 0 ){   // no existe ningún registro borrado
        // setea el hijo izq del dato de _listFreeBlocks
        unsigned short actual = ListFreeBlocks;
        getLeftChildErase(actual);
        while ( getLeftChildErase(actual) != 0) {
            actual = getLeftChildErase(actual);
        }
        std::string stringID = _conversion->fromShort2String( recordID );
        std::string datoBorrado = _conversion->decimalToBinary( stringID );
        this->_disk->write( actual, _conversion->fromStringToConstChar( datoBorrado ) );                  // setea el padre a 0
        this->_disk->write( erasedRecordSpace, "00000000" );        // setea el padre a 0
        this->_disk->write( erasedRecordSpace + 8, "00000000" );    // setea hIZQ a 0
    }
    else{
        cout << "No existe registro para borrar o.O" << endl;
    }
}

/**
 * @brief BTRecordFile::getLeftChildErase
 * @param pNextLeftChild
 * @return
 * Devuelve la proxima posición de el hijo izquierdo que ha sido borrado
 */
unsigned short BTRecordFile::getLeftChildErase(unsigned short pNextLeftChild){
    unsigned short BOF = this->_metadataPtr->getEOF();
    unsigned short recordSize = this->_metadataPtr->getNumberOfRecords();
    // se obtiene al hijo IZQ del dato borrado
    unsigned short erasedRecordSpace = BOF + ( recordSize * (pNextLeftChild - 1) );
    // conversion de const char* a std::string
    std::string nextLeftPosition = _conversion->fromConstChar2String(
                this->_disk->read( erasedRecordSpace + 8, 7 ) );
    // conversion de std::string binario a std::string decimal
    std::string nextLeftPositionDECIMAL = this->_conversion->binaryToDecimal(nextLeftPosition);
    // conversion de std::string a unsigned short
    unsigned short shortNumber = _conversion->fromString2Short( nextLeftPositionDECIMAL );
    cout << "Proximo registro borrado--->" << shortNumber << endl;
    return shortNumber;
}

/**
 * @brief BTRecordFile::readALLRecordsFromDisk
 * Lee los datos qque están en el disco para presentarlos en pantalla
 */
void BTRecordFile::readALLRecordsFromDisk()
{
    cout << "-----------------------------------------------------------------" << endl;
    cout << "$$$$$$$$$$ Lectura de disco $$$$$$$$$$" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    unsigned short contador = 1;
    unsigned short inicio = this->_metadataPtr->getFirstRecordPos();
    cout << this->_metadataPtr->getFirstRecordPos() << endl;
    cout << this->_metadataPtr->getEOF() << endl;
    while( inicio != this->_metadataPtr->getEOF() ){
        const char* padre = this->_disk->read( inicio, 7 );
        std::string stringData1 = _conversion->fromConstChar2String( padre );
        const char* Hizq = this->_disk->read( inicio + 8, 7 );
        std::string stringData2 = _conversion->fromConstChar2String( Hizq );
        const char* Hder = this->_disk->read( inicio + 16, 7 );
        std::string stringData3 = _conversion->fromConstChar2String( Hder );
        const char* data = this->_disk->read( inicio + 24, 7 );
        std::string stringData4 = _conversion->fromConstChar2String( data );

        cout << "----- REGISTRO # " <<  contador << " -----" << endl;
        cout << "Padre--> ";
        cout << _conversion->binaryToDecimal(stringData1);
        cout << " hIzq--> ";
        cout << _conversion->binaryToDecimal(stringData2);
        cout << " hDer--> ";
        cout << _conversion->binaryToDecimal(stringData3);
        cout << " Dato--> ";
        cout << _conversion->binaryToString(stringData4) << endl;

        inicio += this->_metadataPtr->getRecordSize();
        contador++;
    }
    cout << "-------- Fin de los datos en el disco!! --------" << endl;
}

//------------------------------------------------------------------------------
//   FIN INSERCION Y BORRADO DE DATOS EN DISCO
//------------------------------------------------------------------------------

/**
 * @brief printDataStructureByUser imprime cómo está conformado el registro
 * según los campos que ingresó el usuario
 */
void BTRecordFile::printDataStructureByUser()
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
BTRecord *BTRecordFile::deleteRecord(unsigned short pDatoBorrado)
{
    if (this->getListFreeBlocks() == 0) {// no bloques libres no hay ninguno borrado
        cout << "--------------------------" << endl;
        cout << "Borrando el registro # " << pDatoBorrado << endl;
        cout << "--------------------------" << endl;
        this->setListFreeBlocks(pDatoBorrado);
        _registryArray[pDatoBorrado].setParentPtr(0);
        _registryArray[pDatoBorrado].setLeftChildPtr(0);
        this->setListFreeBlocks(pDatoBorrado);
    } else if (this->getListFreeBlocks() != 0) { // ya hay registros borrados
        cout << "--------------------------" << endl;
        cout << "Borrando el registro # " << pDatoBorrado << endl;
        cout << "--------------------------" << endl;
        // setea el hijo izq del dato de _listFreeBlocks
        unsigned short actual = this->_listFreeBlocks;
        while (_registryArray[actual].getLeftChildPtr() != 0) {
            actual = _registryArray[actual].getLeftChildPtr();
        }
        this->_registryArray[actual].setLeftChildPtr(pDatoBorrado);
        this->_registryArray[pDatoBorrado].setParentPtr(0);
        this->_registryArray[pDatoBorrado].setLeftChildPtr(0);
    } else {
        cout << "No existe registro para borrar." << endl;
    }
}

/**
 * @brief BTRecordFile::printArrayRecord
 * @return
 * Imprime la constitución de los registros(padre,hijos)
 */
void BTRecordFile::printArrayRecord() const
{
    // TODO pasar esta función para que ejecute a un solo registro y luego
    // aquí iterar sobre el arreglo
    cout << "   Record #" << setw(15) << "Parent" << setw(15)
         << "LeftChild" << setw(15) << "RightChild" << endl;
    for (int i = 1; i < this->getCounter(); i++) {
        cout << setw(7) << i << setw(15) <<
             _registryArray[i].getParentPtr() << setw(15) <<
             _registryArray[i].getLeftChildPtr() << setw(15) <<
             _registryArray[i].getRightChildPtr() << setw(15) << "\n";
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

/**
 * @brief BTRecordFile::readRecordFromDiskTest
 * @param pDisk
 * @param pRecordID
 * Hace la lectura de un registro en la RAM
 */
void BTRecordFile::readRecordFromDiskTest(Disk pDisk, unsigned short pRecordID)
{
    const char *padre = pDisk.read( 0, 7 );
    const char *hizq = pDisk.read( 8, 7 );
    const char *hder = pDisk.read( 16, 7 );
    std::string father(padre);          // obtiene el padre
    std::string HI(hizq);               // obtiene el hijo izq
    std::string HD(hder);               // obtiene el hijo der
    unsigned short _sizeCounter = 24;       // inicio de la data
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
        cout << sortUserDataFromDisk(DATOSTR, _conversion, *data) << endl;
        tmp = tmp->getNextPtr();
    }
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
std::string BTRecordFile::sortUserDataFromDisk(std::string pData,
        Converter *pConversion, char pTipo)
{
    std::string finalBinaryRecord;

    if (pTipo == BTRecordFileMetadata::STRING ||
        pTipo == BTRecordFileMetadata::CHAR) { // cadena no de numeros
        finalBinaryRecord = pConversion->binaryToString(pData);
    } else { // son solo numeros
        finalBinaryRecord = pConversion->binaryToDecimal(pData);
    }

    return finalBinaryRecord;
}
