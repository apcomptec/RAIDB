/*******************************************************************************
 * File: RecordDataType.h
 * Author: Brallan Aguilar
 * Description: Tipos de datos de un registro
 * Reference:
 ******************************************************************************/

#ifndef RECORDDATATYPE_H
#define RECORDDATATYPE_H

#include <iostream>
#include "IRecordDataType.h"

template<typename DATATYPE>
class RegistryDataType: public IRecordDataType
{
public:

    /**
     * @brief RegistryDataType Constructor
     * @param pName Nombre del campo de registro
     * @param pData Dato contenido
     * @param pLength Tamaño del tipo de datos bytes (B). Si no se especifica,
     * se le otorga un cero para así calcularlo automáticamente (en caso que
     * no sea un string)
     */
    RegistryDataType(char const* &pName, DATATYPE &pData,
                     unsigned short pLength = 0);

    /**
     * @brief getName
     * @return
     */
    virtual char const* getName() const;

    /**
     * @brief setName
     * @param pName
     */
    virtual void setName(const char *pName);

    /**
     * @brief getData
     * @return El dato de campo de registro
     */
    DATATYPE getData() const;

    /**
     * @brief setData Establece un nuevo dato de registro
     * @param pData Nuevo dato
     */
    void setData(DATATYPE &pData);

    /**
     * @brief getSize Tamaño del dato de registro
     */
    virtual unsigned short getSize() const;

    /**
     * @brief printDataInfo Imprime el dato y su tamaño
     */
    void printDataInfo() const;

private:

    /**
     * @brief _name
     */
    const char *_name;

    /**
     * @brief _data Dato del campo de registro
     */
    DATATYPE _data;

    /**
     * @brief _size Tamaño del campo de registro
     */
    unsigned short _size;
};

// -----------------------------------------------------------------------------
// IMPLEMENTACIÓN DEL TEMPLATE
// -----------------------------------------------------------------------------

template<typename DATATYPE>
RegistryDataType<DATATYPE>::RegistryDataType(const char *&pName, DATATYPE &pData,
        unsigned short pLength)
    : _name(pName),
      _data(pData),
      _size(pLength == 0 ? sizeof(DATATYPE) : pLength)
{
    // vacío
}

template<typename DATATYPE>
const char *RegistryDataType<DATATYPE>::getName() const
{
    return _name;
}

template<typename DATATYPE>
void RegistryDataType<DATATYPE>::setName(const char *pName)
{
    _name = pName;
}

template<typename DATATYPE>
DATATYPE RegistryDataType<DATATYPE>::getData() const
{
    return _data;
}

template<typename DATATYPE>
void RegistryDataType<DATATYPE>::setData(DATATYPE &pData)
{
    _data = pData;
}

template<typename DATATYPE>
unsigned short RegistryDataType::getSize() const
{
    return _size;
}

template<typename DATATYPE>
void RegistryDataType<DATATYPE>::printDataInfo() const
{
    std::cout << "\nNombre: " << _name
              << "\nDato: \t" << _data
              << "\nTamaño: " << _size << "B\n";
}

#endif // RECORDDATATYPE_H
