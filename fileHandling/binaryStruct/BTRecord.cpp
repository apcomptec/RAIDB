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
    std::cout << "Parent" << "LeftChild" << "RightChild" << "DataList\n";

}

std::string BTRecord::castRecordToBinary()
{
    Converter *conversion = new Converter();
    conversion->decimalToBinary( std::to_string( _parentPtr ) );
    conversion->decimalToBinary( std::to_string( _leftChildPtr ) );
    conversion->decimalToBinary( std::to_string( _rightChildPtr ) );
    DLLNode<IRecordDataType*> *tmp = _dataListPtr->getHeadPtr();
    RecordDataType<std::string> *data;
    while (tmp->getNextPtr() != nullptr) {
        data = dynamic_cast<RecordDataType<std::string>*>(tmp->getData());
        conversion->stringToBinary(&data->getDataPtr());
        tmp = tmp->getNextPtr();
    }
}
