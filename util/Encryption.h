#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>
#include <QString>
#include <QCryptographicHash>
#include "util/randomnumber.h"
#include "util/Converter.h"

using namespace std;

class Encryption
{
public:
    Encryption();

    std::string passwordEncryption(string pPassword);
    std::string passWordDecryption(string pPassword);
    std::string generateRandomPassword();

private:
    Converter *_conversor;
    RandomNumber *_aleatorioNumeros;        // aleatorio para numeros
    RandomNumber *_aleatorioLetrasM;        // aleatorio para letras mayúsculas
    RandomNumber *_aleatorioLetrasm;        // aleatorio para letras minúsculas
    //RandomNumber *_aleatorioOpciones;        // aleatorio para opciones
    std::string generateRandomPasswordAUX(unsigned short pValue);
};

#endif // ENCRYPTION_H
