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
class RecordDataType: public IRecordDataType
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
    RecordDataType(std::string &pName, DATATYPE &pData, unsigned short &pSize);

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORDDATATYPE
// -----------------------------------------------------------------------------
    virtual unsigned short getSize() const;
    virtual std::string getName() const;
    virtual void setName(std::string &pName);
    virtual void printDataInfo() const;
// -----------------------------------------------------------------------------

    /**
     * @brief getData
     * @return
     */
    const DATATYPE *getDataPtr() const;

    /**
     * @brief setData
     * @param pData
     */
    void setData(DATATYPE *pDataPtr);

private:

    /**
     * @brief _name
     */
    std::string _name;

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
RecordDataType<DATATYPE>::RecordDataType(std::string &pName, DATATYPE &pData,
        unsigned short &pSize)
    : _name(pName),
      _data(pData),
      _size(pSize)
{
    // vacío
}

template<typename DATATYPE>
std::string RecordDataType<DATATYPE>::getName() const
{
    return _name;
}

template<typename DATATYPE>
void RecordDataType<DATATYPE>::setName(std::string &pName)
{
    _name = pName;
}

template<typename DATATYPE>
const DATATYPE *RecordDataType<DATATYPE>::getDataPtr() const
{
    return &_data;
}

template<typename DATATYPE>
void RecordDataType<DATATYPE>::setData(DATATYPE *pDataPtr)
{
    _data = *pDataPtr;
}

template<typename DATATYPE>
unsigned short RecordDataType<DATATYPE>::getSize() const
{
    return _size;
}

template<typename DATATYPE>
void RecordDataType<DATATYPE>::printDataInfo() const
{
    std::cout << "\nNombre: " << _name
              << "\nDato: \t" << _data
              << "\nTamaño: " << _size << "B\n";
}

#endif // RECORDDATATYPE_H
