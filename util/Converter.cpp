#include <sstream>
#include <iostream>
#include <QString>
#include <QDebug>
#include <bitset>
#include "Converter.h"

Converter::Converter()
{
    // vacío
}

/**
 * @brief Converter::decimalToBinary
 * Convierte números (cadenas de strings) de una base a otra
 */
std::string Converter::decimalToBinary(const std::string &pDecimalNumber)
{
    std::string str(pDecimalNumber);   // Convert from std::string 2 Qstring
    QString qstrDecimalNumber(str.c_str());     // donde qstr es el QString
    qDebug() << qstrDecimalNumber; // << qDebugendl;      // número decimal

    bool ok = false;

    //  convierte un string de decimal a binario
    QString binaryNumber =
        QString::number(qstrDecimalNumber.toLongLong(&ok, 10), 2);
    qDebug() << binaryNumber; // "111"
    std::string stringBinary = binaryNumber.toStdString();
    return stringBinary;

}

/**
 * @brief Converter::binaryToDecimal
 * @param pBinaryString
 * Convierte números de binario a decimal
 */
std::string Converter::binaryToDecimal(const std::string &pBinaryString)
{
    std::string str(pBinaryString); // Convert from std::string 2 Qstring
    QString qstrDecimalNumber(str.c_str()); // donde qstr es el QString
    qDebug() << qstrDecimalNumber; // número decimal

    bool ok = false;
    QString decimalNumber =
        QString::number(qstrDecimalNumber.toLongLong(&ok, 2), 10);
    qDebug() << decimalNumber; // número convertido a decimal
    std::string stringDecimal = decimalNumber.toStdString();
    return stringDecimal;
}

/**
 * @brief Converter::stringToBinary
 * @param pStringLetters
 * Función para convertir std::string a binario
 */
std::string Converter::stringToBinary(const std::string &pStringLetters)
{
    std::string string;
    for (std::size_t i = 0; i < pStringLetters.size(); ++i) {
        std::bitset<8> array(pStringLetters.c_str()[i]);
        string += array.to_string();
    }

    return string;
}

/**
 * @brief Converter::binaryToString
 * @param pBinaryString
 * Conversión de binario a String
 */
std::string Converter::binaryToString(const std::string &pBinaryString)
{
    std::string temp, result;
    const char SIZEOFBINARY = 8;

    for (unsigned short counter = pBinaryString.length() / SIZEOFBINARY,
         pos = 0; counter > 0; counter--, pos += SIZEOFBINARY) {

        temp = pBinaryString.substr(pos, SIZEOFBINARY);

        std::string str(binaryToDecimal(temp));
        QString asciiCharacter(str.c_str());

        char binaryToStringChar = asciiCharacter.toInt();

        result.append(numericCharToString(binaryToStringChar));
    }

    return result;
}

std::string Converter::numericCharToString(char &pChar)
{
    std::stringstream ss;
    std::string string;

    ss << pChar;
    ss >> string;

    return string;
}
