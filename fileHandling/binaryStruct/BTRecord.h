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
     * @param pRegistryStructPtr Puntero constante a una lista constante de
     * datos de registro
     */
    BTRecord(const DLL<char> * const pRegistryStructPtr);

    BTRecord();


// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORD
// -----------------------------------------------------------------------------
    virtual DLL<IRecordDataType *> *getDataListPtr();
    virtual void setDataList(DLL<IRecordDataType *> *);
    virtual const DLL<char> *getRecordStructPtr();
    virtual void setRecordStruct(DLL<char> *);
// -----------------------------------------------------------------------------

//    DLLNode *getParentPtr() const;
//    void setParentPtr(DLLNode *parentPtr);

//    DLLNode *getLeftChildPtr() const;
//    void setLeftChildPtr(DLLNode *leftChildPtr);

//    DLLNode *getRightChildPtr() const;
//    void setRightChildPtr(DLLNode *rightChildPtr);

private:

    /**
     * @brief _parentPtr Puntero padre del registro
     * @brief _leftChildPtr Puntero al hijo izquierdo del registro
     * @brief _rightChildPtr Puntero al hijo derecho del registro
     */
//    DLLNode *_parentPtr, *_leftChildPtr, *_rightChildPtr;

    /**
     * @brief _registryStructPtr Puntero a una lista doble con las cabeceras de
     * campo del registro.
     */
//    const DLL<char> * const _recordStructPtr;

    /**
     * @brief _dataListPtr Lista con los elementos de datos del registro
     */
    DLL<IRecordDataType *> *_dataListPtr;
};

#endif // BTRECORD_H
