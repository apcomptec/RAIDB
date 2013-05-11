/*******************************************************************************
 * File: BTRecord.h
 * Author: Brallan Aguilar
 * Description: Representa un registro en un árbol binario
 * Reference:
 ******************************************************************************/

#ifndef BTRECORD_H
#define BTRECORD_H

#include "dataStructure/DLL.h"
#include "fileHandling/RecordDataType.h"
#include "fileHandling/IRecord.h"

class BTRecord: public IRecord
{
public:

// -----------------------------------------------------------------------------
// PROTOTIPO DE CONSTANTES
// -----------------------------------------------------------------------------
    static const char STRING;
    static const char CHAR;
    static const char SHORT;
    static const char INT;
    static const char DOUBLE;
    static const char BOOL;
// -----------------------------------------------------------------------------

    /**
     * @brief BTRecord Constructor
     */
    BTRecord();

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORD
// -----------------------------------------------------------------------------
    virtual DLL<IRecordDataType *> *getDataListPtr() const;
    virtual void setDataList(DLL<IRecordDataType *> *);
    virtual unsigned short *getIndex() const;
    virtual void setIndex(unsigned short *pIndexPtr);
// -----------------------------------------------------------------------------

    unsigned short getParentPtr() const;
    void setParentPtr(unsigned short pParentPtr);

    unsigned short getLeftChildPtr() const;
    void setLeftChildPtr(unsigned short pLeftChildPtr);

    unsigned short getRightChildPtr() const;
    void setRightChildPtr(unsigned short pRightChildPtr);

    void printRecord() const;

private:

    /**
     * @brief _parentPtr Puntero padre del registro
     * @brief _leftChildPtr Puntero al hijo izquierdo del registro
     * @brief _rightChildPtr Puntero al hijo derecho del registro
     */
    unsigned short *_indexPtr, _parentPtr, _leftChildPtr, _rightChildPtr;

    /**
     * @brief _dataListPtr Lista con los elementos de datos del registro
     */
    DLL<IRecordDataType *> *_dataListPtr;
};

#endif // BTRECORD_H
