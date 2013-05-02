/*******************************************************************************
 * File: ARecord.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de ARecord.h
 * Reference:
 ******************************************************************************/

#include "ARecord.h"

ARecord::ARecord(const DLL<IRecordDataType *> * const pRegistryStructPtr)
    : _registryStructPtr(pRegistryStructPtr)
{
    // vacío
}
