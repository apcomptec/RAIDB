/*******************************************************************************
 * File: BTRecordFile.cpp
 * Author: Brallan Aguilar y Daniel Araya
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include <iomanip>
#include "BTRecordFile.h"

BTRecordFile::BTRecordFile()
    : _metadataPtr(new BTRecordFileMetadata())
{
    _metadataPtr->getRecordStructPtr();
}

BTRecordFile::BTRecordFile(BTRecordFileMetadata *pMetadata)
    : _metadataPtr(pMetadata)
{
    this->_registryArray = new BTRecord[100];
    this->_counter = 1;
    this->_listFreeBlocks = 0; // lista de bloques libres está vacía
}


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

}

void BTRecordFile::setRecordList(DLL<IRecord *> *pListPtr)
{

}

BTRecord *BTRecordFile::insertRecord(DLL<IRecordDataType *> *pListPtr)
{
    unsigned short hDer = this->_registryArray[3].getRightChildPtr();
    BTRecord *newRecord = new BTRecord();
    newRecord->setDataList(pListPtr);
    if (this->getListFreeBlocks() == 0) {
        if (this->_registryArray == NULL) {   //arreglo vacío
            newRecord->setParentPtr(0);    // puede ser 0 ó -1
            newRecord->setLeftChildPtr(0);
            newRecord->setRightChildPtr(0);
            this->_registryArray[1] = *newRecord;    // inicio en la posición 1
        } else {
            this->_registryArray[_counter] = *newRecord;
            newRecord->setParentPtr(_counter / 2);      //// setea el padre
            (this->_registryArray[_counter]).setParentPtr(_counter / 2);
            if ((_counter % 2) == 0) {    ////si el numero es par es hijo izquierdo
                newRecord->setLeftChildPtr(0);      //// no tiene hijos
                newRecord->setRightChildPtr(0);      //// no tiene hijos
                (this->_registryArray[newRecord->getParentPtr()])
                        .setLeftChildPtr(_counter);
            } else {
                newRecord->setRightChildPtr(0);     //// no tiene hijos
                newRecord->setLeftChildPtr(0);      //// no tiene hijos
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

void BTRecordFile::printDataStructureByUser()
{
    std::cout << "Los registros tienen la siguiente estructura: \n\n";

    DLLNode<IRecordDataType *> *current =
        _metadataPtr->getRecordStructPtr()->getHeadPtr();

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

BTRecord *BTRecordFile::printArrayRecord() const
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

BTRecord *BTRecordFile::insertRecord()
{
    printDataStructureByUser();
}

void BTRecordFile::readRecordFromDiskTest( Disk pDisk, unsigned short pRecordID ){
    const char *padre = pDisk.read( 0, 15 );
    const char *hizq = pDisk.read( 16, 31 );
    const char *hder = pDisk.read( 32, 47 );
    std::string father(padre);       // obtiene el padre
    std::string HI(hizq);       // obtiene el hijo izq
    std::string HD(hder);       // obtiene el hijo der
    unsigned short _sizeCounter = 48;       // inicio de la data
    DLL<IRecordDataType*> *tmp1 = _metadataPtr->getRecordStructPtr();
    DLLNode<IRecordDataType*> *tmp = tmp1->getHeadPtr();
    RecordDataType<std::string> *data;

    cout << "Binario " << father << " " << HI << " " << HD << endl;
    Converter *conversion = new Converter();
    std::string P = conversion->binaryToDecimal(father);
    std::string PHI = conversion->binaryToDecimal(HI);
    std::string PHD = conversion->binaryToDecimal(HD);
    cout << P << " " << PHI << " " << PHD << " ";
    while( tmp != nullptr ){
        pDisk.read( _sizeCounter, (_sizeCounter +  (tmp->getData()->getSize() * 8)) - 1);
        data = dynamic_cast<RecordDataType<std::string>*>(tmp->getData());
        _sizeCounter += (tmp->getData()->getSize() * 8);
        cout << sortUserDataFromDisk( *data->getDataPtr(), conversion ) << " ";
        tmp = tmp->getNextPtr();
    }
}

std::string BTRecordFile::sortUserDataFromDisk( std::string pData, Converter *pConversion )
{
    std::string finalBinaryRecord;
    std::string str( pData ); // Convert from std::string 2 Qstring
    QString qstrData(str.c_str()); // donde qstr es el QString

    if ( !pConversion->verificaValidezInt( qstrData ) ){ // cadena no de numeros
        finalBinaryRecord = pConversion->binaryToString( pData );
    }
    else{   // son solo numeros
        finalBinaryRecord = pConversion->binaryToDecimal( pData );
    }
    return finalBinaryRecord;
}

