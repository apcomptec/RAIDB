#include "Converter.h"

Converter::Converter()
{
}


void Converter::decimal2Binary()
{
    QString hexadecimalNumber = "0xDEADBEEF";
    QString decimalNumber = "7";

    bool ok = false;
    QString binaryNumber = QString::number(hexadecimalNumber.toLongLong(&ok, 16), 2);
    QString binaryNumber1 = QString::number(decimalNumber.toLongLong(&ok, 10), 2);

    qDebug() << binaryNumber;   // "11011110101011011011111011101111"
    qDebug() << binaryNumber1;  // "111"
}
