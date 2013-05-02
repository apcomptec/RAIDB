/*******************************************************************************
 * File: RecordData.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de RecordData.h
 * Reference:
 ******************************************************************************/

#include "RecordData.h"

RecordData::RecordData()
{
    // vacío
}

void RecordData::insertField(IRecordDataType *pDataType)
{
    _dataList.insertAtFront(pDataType);
}
