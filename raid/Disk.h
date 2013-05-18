/*******************************************************************************
 * File: Disk.h
 * Author: Brallan Aguilar
 * Description: Representación de un disco mediante un archivo bin
 * Reference:
 ******************************************************************************/

#ifndef DISK_H
#define DISK_H

#include <string>
#include "dataStructure/DLL.h"

class BTRecordFile;

class Disk
{

    friend class BTRecordFile;

public:

    /**
     * @brief Disk Constructor
     * @param pId Identificador del disco
     * @param pSize Tamaño del disco en MB
     * @param pBlockSize Tamaño del bloque del disco en bytes. Por defecto, será
     * de 512B
     */
    Disk(unsigned const short &pId, unsigned const short &pSize,
         unsigned short pBlockSize = 512);

    /**
     * @brief write
     * @param pLine
     * @param pBuffer
     */
    void write(const unsigned short &pLine, const char *pBuffer);

    char read(const unsigned &pLine, const unsigned short &pLineLength);

private:

    /**
     * @brief _id ID del disco
     * @brief _size Tamaño del disco en MB
     * @brief _blockSize Tamaño de bloques en el disco en bytes
     */
    unsigned const short ID, SIZE, BLOCK_SIZE;

    /**
     * @brief POTENCY Define la potencia de tamaño del disco. Por ejemplo, si es
     * 10, se refiere a 2^10 B (o kB), o 20 (MB), ...
     */
    static const char POTENCY;


    /**
     * @brief _name Nombre del disco
     */
    std::string _name;

    /**
     * @brief _freeBlockList Contiene la lista de bloques libres en el disco
     */
    DLL<unsigned int> _freeBlockList;

    /**
     * @brief createDisk se encarga de iniciar el disco con el tamaño
     * especificado
     */
    void createDisk();

    /**
     * @brief createFile
     * @return Bloque que le corresponde al archivo
     */
    unsigned int createFile();

    unsigned short sizeOfChar(const char* pChar);

    void fillBlockList();

    unsigned int computeNumberOfBlocks();

    std::string convertNumericCharToString(char pChar);
};

#endif // DISK_H
