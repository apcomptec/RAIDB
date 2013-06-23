/*******************************************************************************
 * File: BTRecordFile.h
 * Author: Brallan Aguilar y Daniel Araya
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef BTRECORDFILE_H
#define BTRECORDFILE_H

#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/binaryStruct/BTRecord.h"
#include "fileHandling/IRecordFile.h"
#include <iostream>
#include <iomanip>
#include <QDebug>
#include "raid/Disk.h"
#include "util/Converter.h"

using namespace std;

class BTRecordFile: public IRecordFile
{

public:

    /**
     * @brief BTRecordFile sobrecarga de constructor
     * @param pMetadata Lista con los metadatos proveidos por el usuario
     */
    BTRecordFile(BTRecordFileMetadata * const pMetadata);

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORDFILE
// -----------------------------------------------------------------------------
    virtual BTRecordFileMetadata *getMetadata() const;
    virtual void setMetadata(IMetadata *pMetadataPtr);
    virtual DLL<IRecord *> *getRecordList() const;
    virtual void setRecordList(DLL<IRecord *> *);
    virtual BTRecord *insertRecord(DLL<IRecordDataType *> *pListPtr);
//    virtual BTRecord *deleteRecord(IMetadata *pRecordPtr);
    virtual BTRecord *deleteRecord(unsigned short recordID);
//    virtual BTRecord *searchRecord(BTRecord *pRecordPtr) const;
    virtual unsigned short showFragmentation() const;
    virtual bool defragFile();
// -----------------------------------------------------------------------------

    BTRecord *getRegistryArray() const;
    void setRegistryArray(BTRecord *pRegistryArray);
    Disk *getDisk() const;
    void setDisk( Disk *pDisk );
    int getCounter() const;
    void setCounter(int counter);
    unsigned short getListFreeBlocks() const;
    void setListFreeBlocks(unsigned short pListFreeBlocks);
    ~BTRecordFile();
    void readRecordFromDiskTest( Disk pDisk, unsigned short pRecordID );

// -----------------------------------------------------------------------------
// MÉTODOS QUE SIRVEN PARA LA INSERCIÓN y BORRADO DE REGISTROS EN DISCO
    void insertRecord2Disk( DLL<IRecordDataType *> *pListPtr ); // INSERCION DE REGISTROS EN DISCO
    void deleteRecordFromDisk(unsigned short recordID );        // BORRADO DE UN REGISTRO
    void readALLRecordsFromDisk();                              // LECTURA DE TODOS LOS REGISTROS
    void readOneRecordFromDisk( unsigned short recordID );      // LECTURA DE UN REGISTRO
    void saveMetadata2Disk();                                   // GUARDA LA METADATA ACTUAL
    void loadMetadata();                                        // CARGA LA METADATA ACTUAL
    void dataClassification( std::string *pDatosUsuario );
    void loadUserInfo(DLL<IRecordDataType *> *pTmp1, std::string pTipo, std::string pTamano, std::string pTitulo);
// -----------------------------------------------------------------------------

    std::string getIdNextBlock() const;
    void setIdNextBlock(const std::string &idNextBlock);
    unsigned short computeMaxSizeOfRegistryInBlock(); // calcula max cantidad de registros por bloque
    unsigned short getMaxSizeOfRegistryInBlock() const;
    void setMaxSizeOfRegistryInBlock(unsigned short maxSizeOfRegistryInBlock);

private:
    BTRecordFileMetadata *_metadataPtr;
    Disk *_disk;
    Disk *_diskMetadata;
    int _counter;       //llevará la cantidad de registros insertados
    Converter *_conversion;
    int _sizeOwner_FileName;
    unsigned short _cantidadDatosUser;
    std::string _idNextBlock;
    unsigned short _maxSizeOfRegistryInBlock;   // dice cual es la cantidad máxima de registros en un bloque

    BTRecord *_registryArray;
    unsigned short _listFreeBlocks;
    void insertRecordAUX(BTRecord *pNewRecord, unsigned short pHDer);
    void printDataStructureByUser();
    string sortUserDataFromDisk(std::string pData , char pTipo );   //clasifica los datos en ints, strings, etc...

// -----------------------------------------------------------------------------
// MÉTODOS QUE SIRVEN PARA LA INSERCIÓN y BORRADO DE REGISTROS EN DISCO
    void modifyLastTreeRegistry(unsigned short pRecordNumber,
                                unsigned short pChangePositon);
    std::string getUserRecordData( DLL<IRecordDataType *> *pListPtr );
    unsigned short getLeftChildErase(unsigned short pNextLeftChild);
    void aux_InsertRecord2Disk(DLL<IRecordDataType *> *pListPtr);
// -----------------------------------------------------------------------------

};

#endif // BTRECORDFILE_H
