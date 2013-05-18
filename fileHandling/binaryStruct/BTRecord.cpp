/*******************************************************************************
 * File: BTRecord.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de BTRecord.h
 * Reference:
 ******************************************************************************/

#include "BTRecord.h"
#include "util/Converter.h"

BTRecord::BTRecord()
{
    // vacío
}

DLL<IRecordDataType *> *BTRecord::getDataListPtr() const
{
    return _dataListPtr;
}

void BTRecord::setDataList(DLL<IRecordDataType *> *pDataListPtr)
{
    _dataListPtr = pDataListPtr;
}


unsigned short BTRecord::getParentPtr() const
{
    return _parentPtr;
}

void BTRecord::setParentPtr(unsigned short pParentPtr)
{
    _parentPtr = pParentPtr;
}

unsigned short BTRecord::getLeftChildPtr() const
{
    return _leftChildPtr;
}

void BTRecord::setLeftChildPtr(unsigned short pLeftChildPtr)
{
    _leftChildPtr = pLeftChildPtr;
}

unsigned short BTRecord::getRightChildPtr() const
{
    return _rightChildPtr;
}

void BTRecord::setRightChildPtr(unsigned short pRightChildPtr)
{
    _rightChildPtr = pRightChildPtr;
}

void BTRecord::printRecord() const
{
    cout <<  "Parent" << setw(15) << "LeftChild" << setw(15) << "RightChild" << endl;
    cout << setw(7) << _parentPtr << setw(15) << _leftChildPtr << setw(15) <<
             _rightChildPtr << setw(15);
    DLLNode<IRecordDataType*> *tmp = _dataListPtr->getHeadPtr();
    while( tmp->getNextPtr() != nullptr ){
        cout << tmp->getData() << setw(15) << endl;
        tmp = tmp->getNextPtr();
    }
    cout << "\n";

}

std::string BTRecord::castRecordToBinary()
{
    std::string finalBinaryRecord;  // concatenacion del registro
    Converter *conversion = new Converter();
    finalBinaryRecord += conversion->decimalToBinary( std::to_string( _parentPtr ) );
    finalBinaryRecord += conversion->decimalToBinary( std::to_string( _leftChildPtr ) );
    finalBinaryRecord += conversion->decimalToBinary( std::to_string( _rightChildPtr ) );
    DLLNode<IRecordDataType*> *tmp = _dataListPtr->getHeadPtr();
    RecordDataType<std::string> *data;
    while(tmp->getNextPtr() != nullptr){
        data = dynamic_cast<RecordDataType<std::string>*>(tmp->getData());
        finalBinaryRecord += conversion->stringToBinary( *data->getDataPtr() );
        tmp = tmp->getNextPtr();
    }
    cout << "El registro en BINARIO es: " << "\n"
         << finalBinaryRecord << endl;
    return finalBinaryRecord;
}
