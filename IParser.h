#ifndef IPARSER_H
#define IPARSER_H

#include <iostream>

using namespace std;

class IParser{

public:

    virtual void createFile() = 0;      // Método para crear un archivo
    virtual void readFile() = 0;        // Método para leer un archivo
    virtual void writeFile() = 0;       // Método para escribir un archivo

private:

};

#endif // IPARSER_H
