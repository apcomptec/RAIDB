#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <QString>
#include <QDebug>

using namespace std;

class Converter{

public:
    Converter();
    ~Converter();

    void string2Binary( QString pString );
    void binary2String2( QString pBinaryString );
    void decimal2Binary(std::string pDecimalNumber );

private:


};

#endif // CONVERTER_H
