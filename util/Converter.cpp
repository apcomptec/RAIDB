#include <sstream>
#include "Converter.h"

Converter::Converter()
{
}


/**
 * @brief Converter::decimal2Binary
 * Convierte números (cadenas de strings) de una base a otra
 */
std::string Converter::decimal2Binary(std::string pDecimalNumber)
{
    std::string str(pDecimalNumber);   // Convert from std::string 2 Qstring
    QString qstrDecimalNumber(str.c_str());     // donde qstr es el QString
    qDebug() << qstrDecimalNumber << endl;      // número decimal

    bool ok = false;
    //  convierte un string de decimal a binario
    QString binaryNumber = QString::number(qstrDecimalNumber.toLongLong(&ok, 10), 2);
    qDebug() << binaryNumber << endl;  // "111"
    std::string stringBinary = binaryNumber.toStdString();
    return stringBinary;

}

/**
 * @brief Converter::binary2Decimal
 * @param pBinaryString
 * Convierte números de binario a decimal
 */
QString Converter::binary2Decimal(std::string pBinaryString)
{
    std::string str(pBinaryString);   // Convert from std::string 2 Qstring
    QString qstrDecimalNumber(str.c_str());     // donde qstr es el QString
    qDebug() << qstrDecimalNumber << endl;      // número decimal

    bool ok = false;
    QString decimalNumber = QString::number(qstrDecimalNumber.toLongLong(&ok, 2), 10);
    qDebug() << decimalNumber << endl;  // numero convertido a decimal
    std::string stringDecimal = decimalNumber.toStdString();
    return decimalNumber;
}

/**
 * @brief Converter::string2Binary
 * @param pStringLetters
 * Función para convertir std::string a binario
 */
std::string Converter::string2Binary(std::string pStringLetters)
{
    std::string string;
    for (std::size_t i = 0; i < pStringLetters.size(); ++i) {
        bitset<8> array(pStringLetters.c_str()[i]);
        string += array.to_string();
    }

    return string;
}

/**
 * @brief Converter::binary2String
 * @param pBinaryString
 * Conversión de binario a String
 */
std::string Converter::binary2String(std::string pBinaryString)
{
    unsigned short counter = pBinaryString.length() / 8;
    std::cout << "Counter: " << counter;
    std::string temp, result;
    unsigned short pos = 0;

    for (; counter > 0; counter--) {
        std::cout << "\npos: " << pos;
        temp = pBinaryString.substr(pos, 8);
        std::cout << "\nTemp: " << temp;

        QString hola = binary2Decimal(temp);

        int asciiCharacter = hola.toInt();
        char binaryToStringChar = asciiCharacter;

        result.append(convertNumericCharToString(binaryToStringChar));

        pos += 8;
    }

    return result;
}

std::string Converter::convertNumericCharToString(char pChar)
{
    std::stringstream ss;
    std::string string;

    ss << pChar;
    ss >> string;

    return string;
}
