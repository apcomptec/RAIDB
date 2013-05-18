/*******************************************************************************
 * File: BTRecordFile.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include "BTRecordFile.h"

BTRecordFile::BTRecordFile(BTRecordFileMetadata *pMetadata)
{
    this->_registryArray = new BTRecord[100];
    this->_counter = 1;
    this->_listFreeBlocks = 0; // lista de bloques libres está vacía

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

//BTRecord *BTRecordFile::searchRecord( BTRecord *pRecordPtr ) const
//{
//    //    for ( int i = 1; i < _registryArray->getSize(); i++ ){
//    //        ////NOTA hacer método para comparar OBJETOS
//    //        if( pRecordPtr == _registryArray[i] ){    //encontró el registro
//    //            cout << "¡Registro encontrado!" << endl;
//    //            break;
//    //        }
//    //    }
//    //    cout << "¡No existe registro!" << endl;
//}

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
//    for ( int i = 0; i < _registryArray->getSize(); i++ ){
//        ////NOTA hacer método para comparar OBJETOS
//        if( pRecordPtr == _registryArray[i] ){    //encontró el registro
//            cout << "¡Registro encontrado!" << endl;
//            cout << "¡Procediendo a borrar registro!" << endl;



//            break;
//        }
//    }
//    cout << "¡No existe registro!" << endl;
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

string BTRecordFile::castRecordToBinary()
{

}
