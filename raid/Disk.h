/*******************************************************************************
 * File: Disk.h
 * Author: Brallan Aguilar
 * Description: Representación de un disco mediante un archivo bin
 * Reference:
 ******************************************************************************/

#ifndef DISK_H
#define DISK_H

#include <string>

class Disk
{
public:

    /**
     * @brief Disk Constructor
     * @param pId Identificador del disco
     * @param pSize Tamaño del disco en MB
     * @param pBlockSize Tamaño del bloque del disco en bytes
     */
    Disk(unsigned const short &pId, unsigned const short &pSize,
         unsigned short &pBlockSize);

    /**
     * @brief write
     * @param pLine
     * @param pBuffer
     */
    void write(const unsigned short &pLine, const char *pBuffer);

    char read(const unsigned &pLine, const unsigned short &pLineLength);
//    const char* read(const unsigned &pLine);

private:

    /**
     * @brief _id
     * @brief _size
     * @brief _blockSize
     */
    unsigned const short ID, SIZE, BLOCK_SIZE;

    std::string _name;

    /**
     * @brief POTENCY Define la potencia de tamaño. Por ejemplo, si es 10, se
     * refiere a 2^10 B (o kB), o 20 (MB), ...
     */
    static const char POTENCY;

    /**
     * @brief create
     */
    void create();

    unsigned short sizeOfChar(const char* pChar);
};

#endif // DISK_H
