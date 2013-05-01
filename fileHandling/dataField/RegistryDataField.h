/*******************************************************************************
 * File: RegistryDataField.h
 * Author: Brallan Aguilar
 * Description: Tipos de datos de un registro
 * Reference:
 ******************************************************************************/

#ifndef REGISTRYDATAFIELD_H
#define REGISTRYDATAFIELD_H

#include <iostream>

template<typename DATATYPE>
class RegistryDataField
{
public:

    /**
     * @brief RegistryDataField Constructor
     * @param pData Dato contenido
     * @param pLength Tamaño del tipo de datos bytes (B). Si no se especifica,
     * se le otorga un cero para así calcularlo automáticamente (en caso que
     * no sea un string)
     */
    RegistryDataField(DATATYPE pData, unsigned short pLength = 0);

    /**
     * @brief getData
     * @return El dato de campo de registro
     */
    DATATYPE getData() const;

    /**
     * @brief setData Establece un nuevo dato de registro
     * @param pData Nuevo dato
     */
    void setData(DATATYPE pData);

    /**
     * @brief getSize Tamaño del dato de registro
     */
    void getSize() const;

    /**
     * @brief printDataInfo Imprime el dato y su tamaño
     */
    void printDataInfo() const;

private:

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
RegistryDataField<DATATYPE>::RegistryDataField(DATATYPE pData,
        unsigned short pLength)
    : _data(pData),
      _size(pLength == 0 ? sizeof(DATATYPE) : pLength)
{
    // vacío
}

template<typename DATATYPE>
DATATYPE RegistryDataField<DATATYPE>::getData() const
{
    return _data;
}

template<typename DATATYPE>
void RegistryDataField<DATATYPE>::setData(DATATYPE pData)
{
    _data = pData;
}

template<typename DATATYPE>
void RegistryDataField<DATATYPE>::getSize() const
{
    return _size;
}

template<typename DATATYPE>
void RegistryDataField<DATATYPE>::printDataInfo() const
{
    std::cout << "Dato: \t" << _data << "\nTamaño: " << _size << " B\n";
}

#endif // REGISTRYDATAFIELD_H
