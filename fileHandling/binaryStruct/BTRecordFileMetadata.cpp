/*******************************************************************************
 * File: BTRecordFileMetadata.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include <iostream>
#include "BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"

// -----------------------------------------------------------------------------
// DEFINICIÓN DE CONSTANTES
// -----------------------------------------------------------------------------
const char BTRecordFileMetadata::STRING     = '0';
const char BTRecordFileMetadata::CHAR       = '1';
const char BTRecordFileMetadata::SHORT      = '2';
const char BTRecordFileMetadata::INT        = '3';
const char BTRecordFileMetadata::DOUBLE     = '4';
const char BTRecordFileMetadata::BOOL       = '5';
// -----------------------------------------------------------------------------

BTRecordFileMetadata::BTRecordFileMetadata()
    : _recordStructPtr(new DLL<IRecordDataType*>())
{
    constructMetadata();
}

BTRecordFileMetadata::BTRecordFileMetadata(DLL<IRecordDataType *>
        *pRecordStructPtr, const std::string &pFileName,
        const std::string &pOwner)
    : _recordStructPtr(pRecordStructPtr),
      _fileName(pFileName),
      _owner(pOwner),
      _recordSize(computeRecordSize())
{
    // vacío
}

DLL<IRecordDataType *> *BTRecordFileMetadata::getRecordStruct() const
{
    return _recordStructPtr;
}

std::string BTRecordFileMetadata::getFileName() const
{
    return _fileName;
}

void BTRecordFileMetadata::setFileName(const std::string &pFileName)
{
    _fileName = pFileName;
}

unsigned short BTRecordFileMetadata::getFileSize() const
{
    return _fileSize;
}

std::string BTRecordFileMetadata::getOwner() const
{
    return _owner;
}

void BTRecordFileMetadata::setOwner(const std::string &pOwner)
{
    _owner = pOwner;
}

DLL<unsigned short> *BTRecordFileMetadata::getFreeBlockList() const
{
    return _freeBlockList;
}

void BTRecordFileMetadata::setFreeBlockList(DLL<unsigned short> *pFreeBlockList)
{
    _freeBlockList = pFreeBlockList;
}

DLL<unsigned short> *BTRecordFileMetadata::getUsedBlockList() const
{
    return _usedBlockList;
}

void BTRecordFileMetadata::setUsedBlockList(DLL<unsigned short> *pBlockUsedList)
{
    _usedBlockList = pBlockUsedList;
}

unsigned short BTRecordFileMetadata::getEOF() const
{
    return _eof;
}

void BTRecordFileMetadata::setEOF(const unsigned short &pEOF)
{
    _eof = pEOF;
}

unsigned short BTRecordFileMetadata::getFirstRecordPos() const
{
    return _fr;
}

void BTRecordFileMetadata::setFirstRecordPos(const unsigned short &pPos)
{
    _fr = pPos;
}

unsigned short BTRecordFileMetadata::getRecordSize() const // TODO ¡PROBAR!
{
    return _recordSize;
}

unsigned short BTRecordFileMetadata::getNumberOfRecords() const
{
}

void BTRecordFileMetadata::setNumberOfRecords(const unsigned short &pNumber)
{
}

void BTRecordFileMetadata::constructMetadata()
{
    // NOMBRE DE ARCHIVO
    std::cout << "Escriba el nombre del archivo: ";
    std::cin >> _fileName;

    // DUEÑO DEL ARCHIVO
    // TODO

    // CAMPOS DE REGISTRO

    char field, data;
    unsigned short length;
    std::string name;
    RecordDataType<char> *header;
    bool flag = true;

    std::cout << "Escriba los campos presentes en el registro "
              << "(0 para salir):\n"
              << "1. String\n"
              << "2. Char\n"
              << "3. Short\n"
              << "4. Int\n"
              << "5. Double\n"
              << "6. Bool\n"
              << "> ";
    std::cin >> field;

    while (field != '0') {
        std::cout << "\nNombre del campo: ";
        std::cin >> name;

        std::cout << "\nDefina su tamaño (en B): ";
        std::cin >> length;

        switch (field) {
        case '0': // salir
            break;
        case '1': // String
            name = "string";
            data = STRING;
            break;
        case '2': // Char
            name = "char";
            data = CHAR;
            break;
        case '3': // Short
            name = "short";
            data = SHORT;
            break;
        case '4': // Int
            name = "int";
            data = INT;
            break;
        case '5': // Double
            name = "double";
            data = DOUBLE;
            break;
        case '6': // Bool
            name = "bool";
            data = BOOL;
            break;
        default:
            std::cout << "No existe el tipo especificado\n";
            flag = false;
        }

        if (flag) {
            header = new RecordDataType<char>(name, data, length);
            _recordStructPtr->insertAtBack(header);
        }

        std::cout << "Escriba los campos presentes en el registro "
                  << "(0 para salir):\n"
                  << "1. String\n"
                  << "2. Char\n"
                  << "3. Short\n"
                  << "4. Int\n"
                  << "5. Double\n"
                  << "6. Bool\n"
                  << "> ";
        std::cin >> field;
    }

    _recordSize = computeRecordSize();

    std::cout << "\n\n";
}

unsigned short BTRecordFileMetadata::computeRecordSize() // TODO PROBAR
{
    // representa la cantidad de datos primarios en el registro que son padre,
    // hijo izquierdo y derecho
    const unsigned short NUMBER_OF_PRIMARY_DATA = 3;

    // indica el tamaño en bytes de los datos padre, hijo izquierdo e hijo
    // derecho en el registro
    const unsigned short PRIMARY_DATA = 4;

    // tamaño del registro
    unsigned short size = NUMBER_OF_PRIMARY_DATA * PRIMARY_DATA;

    DLLNode<IRecordDataType *> *currentDataByUser =
        _recordStructPtr->getHeadPtr();

    while (currentDataByUser != nullptr) {
        size += currentDataByUser->getData()->getSize();
        currentDataByUser++; // FIXME probar si sirve para pasar a siguiente nodo
    }

    return size;
}
