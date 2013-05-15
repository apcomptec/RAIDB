#include "Converter.h"

Converter::Converter()
{
}


/**
 * @brief Converter::decimal2Binary
 * Convierte números (cadenas de strings) de una base a otra
 */
void Converter::decimal2Binary( std::string pDecimalNumber )
{
    std::string str(pDecimalNumber); // Conver from std::string 2 Qstring
    QString qstr(str.c_str());  // donde qstr es el QString
    qDebug() << qstr;
    QString hexadecimalNumber = "0xDEADBEEF";   // número hexadecimal
    QString decimalNumber = "7";                // número decimal

    bool ok = false;
    //  convierte un string de hexadecimal a binario
    QString binaryNumber = QString::number(hexadecimalNumber.toLongLong(&ok, 16), 2);
    //  convierte un string de decimal a binario
    QString binaryNumber1 = QString::number(decimalNumber.toLongLong(&ok, 10), 2);

    qDebug() << binaryNumber;   // "11011110101011011011111011101111"
    qDebug() << binaryNumber1;  // "111"

}
