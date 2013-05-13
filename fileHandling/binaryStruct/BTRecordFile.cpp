/*******************************************************************************
 * File: BTRecordFile.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include "BTRecordFile.h"

BTRecordFile::BTRecordFile( BTRecordFileMetadata *pMetadata )
{
    this->_registryArray = new BTRecord[100];
    this->_counter = 1;
    this->_listFreeBlocks = 0; // lista de bloques libres está vacía
}

DLL<IRecord *> *BTRecordFile::getRecordList() const
{

}

void BTRecordFile::setRecordList(DLL<IRecord *> *pListPtr)
{

}

BTRecordFileMetadata *BTRecordFile::getMetadata() const
{
    return _metadataPtr;
}

void BTRecordFile::setMetadata(BTRecordFileMetadata *pMetadataPtr)
{
    _metadataPtr = pMetadataPtr;
}

void BTRecordFile::insertRecord( DLL<IRecordDataType *> *pListPtr )
{
    BTRecord *newRecord = new BTRecord();
    newRecord->setDataList( pListPtr );
    if ( this->_registryArray == NULL ){  //arreglo vacío
        newRecord->setParentPtr( 0 );  // puede ser 0 ó -1
        newRecord->setLeftChildPtr( 0 );
        newRecord->setRightChildPtr( 0 );
        this->_registryArray[1] = *newRecord;    // inicio en la posición 1
    }
    else{
        this->_registryArray[_counter] = *newRecord;
        newRecord->setParentPtr( _counter / 2 );    //// setea el padre
        (this->_registryArray[_counter]).setParentPtr( _counter / 2 );
        if ( (_counter % 2) == 0 ){   ////si el numero es par es hijo izquierdo
            newRecord->setLeftChildPtr( 0 );    //// no tiene hijos
            newRecord->setRightChildPtr( 0 );    //// no tiene hijos
            (this->_registryArray[newRecord->getParentPtr()])
                    .setLeftChildPtr( _counter );
        }
        else{
            newRecord->setRightChildPtr( 0 );   //// no tiene hijos
            newRecord->setLeftChildPtr( 0 );    //// no tiene hijos
            (this->_registryArray[newRecord->getParentPtr()])
                    .setRightChildPtr( _counter );
        }
    }
    this->_counter++;   // aumenta la posición para insertar el siguiente dato
}

BTRecord *BTRecordFile::deleteRecord( unsigned short pDatoBorrado )
{
    if( this->getListFreeBlocks() == 0 ){// no bloques libres no hay ninguno borrado
        cout << "--------------------------" << endl;
        cout << "Borrando el registro # " << pDatoBorrado << endl;
        cout << "--------------------------" << endl;
        this->setListFreeBlocks( pDatoBorrado );
        _registryArray[pDatoBorrado].setParentPtr( 0 );
        _registryArray[pDatoBorrado].setLeftChildPtr( 0 );
        this->setListFreeBlocks( pDatoBorrado );
    }
    else if ( this->getListFreeBlocks() != 0 ){ // ya hay registros borrados
        cout << "--------------------------" << endl;
        cout << "Borrando el registro # " << pDatoBorrado << endl;
        cout << "--------------------------" << endl;
        // setea el hijo izq del dato de _listFreeBlocks
        unsigned short actual = this->_listFreeBlocks;
        while( _registryArray[actual].getLeftChildPtr() != 0){
            actual = _registryArray[actual].getLeftChildPtr();
        }
        this->_registryArray[actual].setLeftChildPtr( pDatoBorrado );
        this->_registryArray[pDatoBorrado].setParentPtr( 0 );
        this->_registryArray[pDatoBorrado].setLeftChildPtr( 0 );
    }
    else{
        cout << "No existe registro para borrar." << endl;
    }
}

BTRecord *BTRecordFile::searchRecord( BTRecord *pRecordPtr ) const
{
}

BTRecord *BTRecordFile::printArrayRecord() const
{
    cout << "   Record #" << setw( 15 ) << "Parent" << setw( 15 )
         << "LeftChild" << setw( 15 ) << "RightChild" << endl;
    for ( int i = 1; i < this->getCounter(); i++ ){
         cout << setw( 7 ) << i << setw( 15 ) <<
                _registryArray[i].getParentPtr() << setw( 15 ) <<
                _registryArray[i].getLeftChildPtr() << setw( 15 ) <<
                _registryArray[i].getRightChildPtr() << setw( 15 ) << "\n";
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
