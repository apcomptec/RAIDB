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
#include "util/Encryption.h"


class Disk
{
public:
    Encryption *_securityKey;

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
     * @brief write Ejecuta una lectura en disco
     * @param pPos Posición inicial donde hará la escritura
     * @param pBuffer Buffer de escritura de cualquier tamaño
     * @param pBlock Bloque donde hará la escritura. Por defecto se hará en el
     * primero
     */
    void write(const unsigned short &pPos, const char *pBuffer,
               unsigned short pBlock = 1);

    /**
     * @brief read Realiza una lectura en el disco
     * @param pPos Posición donde se va a leer
     * @param pBufferLength Tamaño del buffer de lectura
     * @param pBlock Bloque donde hará la lectura. Por defecto se hará en el
     * primero
     * @return Una cadena char que de pPos hasta pPos + pBufferLength (incluye
     * los extremos). Al no poder abrir el archivo, devuelve un puntero nulo
     *
     */
    char *read(const unsigned &pPos, const unsigned short &pBufferLength,
               unsigned short pBlock = 1);

    /**
     * @brief getID
     * @return Devuelve el identificador numérico del disco
     */
    unsigned short getID();

    /**
     * @brief getBlockSize
     * @return Devuelve el tamaño de bloque del diso
     */
    unsigned short getBlockSize();

    /**
     * @brief getName
     * @return Devuelve el nombre del disco (disk + id)
     */
    std::string getName();

    string generateSecurityKey() const;

private:

    /**
     * @brief ID ID del disco
     * @brief SIZE Tamaño del disco en MB
     * @brief BLOCK_SIZE Tamaño de bloques en el disco en bytes
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
    const std::string NAME;

    /**
     * @brief _freeBlockList Contiene la lista de bloques libres en el disco
     */
    DLL<unsigned int> _freeBlockList;

    /**
     * @brief createDisk se encarga de iniciar el disco con el tamaño
     * especificado
     */
    void createDisk();

// -----------------------------------------------------------------------------
// FUNCIONES AUXILIARES
// -----------------------------------------------------------------------------
    /**
     * @brief createFile
     * @return Bloque que le corresponde al archivo
     */
    unsigned int createFile();

    unsigned short sizeOfChar(const char* pChar);

    void fillBlockList();

    unsigned int computeNumberOfBlocks();

    std::string convertNumericCharToString(char pChar);
// -----------------------------------------------------------------------------
};

#endif // DISK_H
