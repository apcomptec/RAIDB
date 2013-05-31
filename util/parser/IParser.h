/*******************************************************************************
 * File: IParser.h
 * Author: Daniel Araya
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef IPARSER_H
#define IPARSER_H

class IParser
{

public:

    /**
     * @brief readFile Lee un archivo
     */
    virtual void readFile() = 0;

    /**
     * @brief writeFile Escribe un archivo
     */
    virtual void writeFile() = 0;

private:

    /**
     * @brief createFile Crea un archivo
     */
    virtual void createFile() = 0;
};

#endif // IPARSER_H
