/*******************************************************************************
 * File: IRecordDataType.h
 * Author: Brallan Aguilar
 * Description: Clase abstracta que representa un registro
 * Reference:
 ******************************************************************************/

#ifndef IREGISTRYDARATYPE_H
#define IREGISTRYDARATYPE_H

class IRecordDataType
{
public:

    /**
     * @brief getName
     * @return
     */
    virtual char getName() const = 0;

    /**
     * @brief setName
     * @param pName
     */
    virtual void setName(char pName) = 0;

    /**
     * @brief getSize
     * @return
     */
    virtual unsigned short getSize() const = 0;
};

#endif // IREGISTRYDARATYPE_H
