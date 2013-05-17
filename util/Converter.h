#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <QString>
#include <QDebug>
#include <bitset>
#include <string>

using namespace std;

class Converter{

public:
    Converter();
    ~Converter();

    void string2Binary( string pStringLetters );        // conversion de string a binario
    void binary2String( string pBinaryString );         // conversion
    QString decimal2Binary( std::string pDecimalNumber );  // conversion de decimal a binario
    QString binary2Decimal( string pBinaryString );        // conversion de binario a decimal

private:


};

#endif // CONVERTER_H
