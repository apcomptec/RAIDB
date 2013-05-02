/*******************************************************************************
 * File: IRecord.h
 * Author: Brallan Aguilar
 * Description: Interfaz de un registro
 * Reference:
 ******************************************************************************/

#ifndef IRECORD_H
#define IRECORD_H
class IRecord
{
    virtual bool insert(IRecord *pRegistryPtr) const = 0;
    virtual bool modify(IRecord *pRegistryPtr) const = 0;
    virtual IRecord *deleteR(IRecord *pRegistryPtr) const = 0;
};

#endif // IRECORD_H
