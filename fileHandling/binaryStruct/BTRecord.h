/*******************************************************************************
 * File: BTRecord.h
 * Author: Brallan Aguilar
 * Description: Representa un registro en un árbol binario
 * Reference:
 ******************************************************************************/

#ifndef BTRECORD_H
#define BTRECORD_H

#include <iomanip>
#include <iostream>
#include "dataStructure/DLL.h"
#include "fileHandling/RecordDataType.h"
#include "fileHandling/IRecord.h"
#include <QString>

using namespace std;

class BTRecord: public IRecord{

public:

    /**
     * @brief BTRecord Constructor
     */
    BTRecord();

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORD
// -----------------------------------------------------------------------------
    virtual DLL<IRecordDataType *> *getDataListPtr() const;
    virtual void setDataList(DLL<IRecordDataType *> *);
    virtual void printRecord() const;
// -----------------------------------------------------------------------------

    unsigned short getParentPtr() const;
    void setParentPtr(unsigned short pParentPtr);

    unsigned short getLeftChildPtr() const;
    void setLeftChildPtr(unsigned short pLeftChildPtr);

    unsigned short getRightChildPtr() const;
    void setRightChildPtr(unsigned short pRightChildPtr);
    std::string castRecordToBinary();
    //bool verificaValidezInt( QString pDato );

private:

    /**
     * @brief _parentPtr Puntero padre del registro
     * @brief _leftChildPtr Puntero al hijo izquierdo del registro
     * @brief _rightChildPtr Puntero al hijo derecho del registro
     */
    unsigned short _parentPtr, _leftChildPtr, _rightChildPtr;

    /**
     * @brief _dataListPtr Lista con los elementos de datos del registro
     */
    DLL<IRecordDataType *> *_dataListPtr;
};

#endif // BTRECORD_H
