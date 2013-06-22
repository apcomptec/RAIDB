#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <QString>
#include <math.h>
#include <iostream>

using namespace std;

class Converter
{

public:

    /**
     * @brief Converter Constructor
     */
    Converter();

    std::string fromShort2String(unsigned short pShortNumber);


    /**
     * @brief fromString2Short
     * @param pSTDString
     * @return
     */
    unsigned short fromString2Short(const std::string &pSTDString);

    /**
     * @brief fromConstChar2String
     * @param pConstChar
     * @return
     */
    std::string fromConstChar2String(const char *pConstChar);

    /**
     * @brief fromStringToQString
     * @param pSTDString
     * @return
     */
    static QString fromStringToQString(const std::string &pSTDString);

    /**
     * @brief FromStringToConstChar
     * @param pDecimalNumber
     * @return
     */
    const char* fromStringToConstChar(const std::string &pSTDString);

    /**
     * @brief stringToBinary Conversion de string a binario
     * @param pStringLetters
     * @return
     */
    std::string stringToBinary(const std::string &pStringLetters);

    /**
     * @brief binaryToString Conversion de binario a string
     * @param pBinaryString
     * @return
     */
    std::string binaryToString(const std::string &pBinaryString);

    /**
     * @brief decimalToBinary Conversion de decimal a binario
     * @param pDecimalNumber
     * @return
     */
    std::string decimalToBinary(const std::string &pDecimalNumber);

    /**
     * @brief binaryToDecimal Conversion de binario a decimal
     * @param pBinaryString
     * @return
     */
    std::string binaryToDecimal(const std::string &pBinaryString);

    string completeBinary(std::string pBinary);

    bool verificaValidezInt(QString pDato);
    bool verificaValidezDouble(QString pDato);
    double fromString2Double(std::string pDoubleString);
    string fromDouble2String(double pDoubleNumber);
    std::string fromBinaryDouble2String(std::string pDoubleString);
    std::string fromDoubleString2BinaryString(std::string pDoubleString);
    std::string fromBinaryString2DoubleString(std::string pDoubleBinaryString);
    std::string fromInt2String(int pIntNumber);
    int fromString2Int(std::string pIntString);

    unsigned short getFillData() const;
    void setFillData(unsigned short pFillData);


private:

    /**
     * @brief numericCharToString
     * @param pChar Valor numérico
     * @return El valor ascii del char numérico en std::string
     */
    std::string numericCharToString(char &pChar);
    unsigned short _fillData;   // rellena el tamaño de los datos

//    std::string completeBinary(std::string &pBinary);

};

#endif // CONVERTER_H
