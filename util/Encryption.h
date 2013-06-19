#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>
#include <QString>
#include <QCryptographicHash>
#include "util/Converter.h"

using namespace std;

class Encryption
{
public:
    Encryption();

    std::string passwordEncryption(string pPassword);
    std::string passWordDecryption(string pPassword);

private:
    //Converter *_conversor;
};

#endif // ENCRYPTION_H
