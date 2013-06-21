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
    virtual void generateBackUp(unsigned short pAmountDisks,
                            unsigned short pAmountDiskGroups,
                            unsigned short pAmountUsers) = 0;
};

#endif // IPARSER_H
