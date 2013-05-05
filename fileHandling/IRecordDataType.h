/*******************************************************************************
 * File: IRecordDataType.h
 * Author: Brallan Aguilar
 * Description: Interfaz que representa un registro
 * Reference:
 ******************************************************************************/

#ifndef IREGISTRYDARATYPE_H
#define IREGISTRYDARATYPE_H

#include <string>

class IRecordDataType
{
public:

    /**
     * @brief getSize
     * @return
     */
    virtual unsigned short getSize() const = 0;

    /**
     * @brief getName
     * @return
     */
    virtual std::string getName() const = 0;

    /**
     * @brief setName
     * @param pName
     */
    virtual void setName(std::string &pName) = 0;

    /**
     * @brief printDataInfo Imprime el dato, su nombre y tamaño
     */
    virtual void printDataInfo() const = 0;
};

#endif // IREGISTRYDARATYPE_H
