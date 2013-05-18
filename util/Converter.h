#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

class Converter
{

public:

    /**
     * @brief Converter Constructor
     */
    Converter();

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

private:

    /**
     * @brief numericCharToString
     * @param pChar Valor numérico
     * @return El valor ascii del char numérico en std::string
     */
    std::string numericCharToString(char &pChar);

};

#endif // CONVERTER_H
