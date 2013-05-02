/*******************************************************************************
 * File: RecordData.h
 * Author: Brallan Aguilar
 * Description: Interfaz de los tipos de dato de un registro
 * Reference:
 ******************************************************************************/

#ifndef RECORDDATA_H
#define RECORDDATA_H

#include "IRecordDataType.h"
#include "dataStructure/DLL.h"

class RecordData
{
public:
    RecordData();

    void insertField(IRecordDataType *pDataType);
    void buildDataType();
    DLL<IRecordDataType*> getDataTypeList() const;

private:
    DLL<IRecordDataType*> _dataList;
};

#endif // RECORDDATA_H
