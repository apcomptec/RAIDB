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
}

BTRecordFileMetadata *BTRecordFile::getMetadata() const
{
    return _metadataPtr;
}

void BTRecordFile::setMetadata(BTRecordFileMetadata *pMetadataPtr)
{
    _metadataPtr = pMetadataPtr;
}

//DLL<IRecord *> *BTRecordFile::getRecordList() const
//{
//    return _recordListPtr;
//}

//void BTRecordFile::setRecordList(DLL<IRecord *> *pListPtr)
//{
//    _recordListPtr = pListPtr;
//}

void BTRecordFile::insertRecord(DLL<IRecordDataType *> *pListPtr)
{
    //// DLL<IRecordDataType*> deberia contener el padre y los hijos no el
    //// BTRecordFile
    BTRecord *newRecord = new BTRecord();
    newRecord->setDataList( pListPtr );
    if ( this->_registryArray[1] == NULL ){  //arreglo vacío
        ////this->_registryArray[0] = NULL;          // posición vacía
        this->_registryArray[1] = newRecord;    // inicio en la posición 1
        newRecord->setParentPtr( 0 );  // puede ser 0 ó -1
        newRecord->setLeftChildPtr( 0 );
        newRecord->setRightChildPtr( 0 );
    }
    else{
        this->_registryArray[_counter] = *pListPtr;
        newRecord->setParentPtr( _counter / 2 );    //// setea el padre
        if ( (_counter % 2) == 0 ){   ////si el numero es par es hijo izquierdo
            newRecord->setLeftChildPtr( 0 );    //// no tiene hijos
            ////this->_registryArray[newRecord->getParentPtr()]
            ////->setLeftChildPtr( _counter );
            ////hay que hacer funcion q devuelva el objeto para cambiar los hijos
        }
        else{
            newRecord->setRightChildPtr( 0 );   //// no tiene hijos
            ////this->_registryArray[newRecord->getParentPtr()]
            ////->setRightChildPtr( _counter );
        }
    }
    this->_counter++;   // aumenta la posición para insertar el siguiente dato
}

BTRecord *BTRecordFile::deleteRecord( BTRecord *pRecordPtr )
{
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

BTRecord *BTRecordFile::searchRecord(BTRecord *pRecordPtr) const // TODO
{
//    for ( int i = 0; i < _registryArray->getSize(); i++ ){
//        ////NOTA hacer método para comparar OBJETOS
//        if( pRecordPtr == _registryArray[i] ){    //encontró el registro
//            cout << "¡Registro encontrado!" << endl;
//            break;
//        }
//    }
//    cout << "¡No existe registro!" << endl;
}

unsigned short BTRecordFile::showFragmentation() const
{
    return 0; // TODO
}

bool BTRecordFile::defragFile()
{
    return false; // TODO
}
