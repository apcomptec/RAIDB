/*******************************************************************************
 * File: FileSystemParser.h
 * Author: Brallan Aguilar
 * Description: Se encarga de convertir el sistema de archivos en un xml
 * Reference:
 ******************************************************************************/

#ifndef FILESYSTEMPARSER_H
#define FILESYSTEMPARSER_H

#include "dataStructure/IN_aryNode.h"
#include "IParser.h"

class FileSystemParser: public IParser
{
public:
    FileSystemParser(const char *pFileName);

    virtual void readFile();

    virtual void writeFile();

    void writeRecord(IN_aryNode<std::string> * pNode);

private:

    const char *const FILE_NAME;

    virtual void createFile();
};

#endif // FILESYSTEMPARSER_H
