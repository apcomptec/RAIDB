#include <sstream>
#include <iostream>
#include <QString>
#include <QDebug>
#include <bitset>
#include "Converter.h"

Converter::Converter()
{
    this->_fillData = 0;    // no hay relleno de datos
}

/**
 * @brief Converter::getFillData
 * @return
 */
unsigned short Converter::getFillData() const
{
    return _fillData;
}

/**
 * @brief Converter::setFillData
 * @param fillData
 */
void Converter::setFillData(unsigned short pFillData)
{
    this->_fillData = pFillData;
}

/**
 * @brief Converter::fromShort2String
 * @param pShortNumber
 * @return
 * Conversión de unsigned short a std::string
 */
std::string Converter::fromShort2String(unsigned short pShortNumber)
{
    return std::to_string(pShortNumber);
}

/**
 * @brief Converter::fromString2Short
 * @param pSTDString
 * @return shortNumber
 * Conversió de std::string a unsigned short
 */
unsigned short Converter::fromString2Short(const std::string &pSTDString)
{
    QString qstString = this->fromStringToQString(pSTDString);
    unsigned short shortNumber = qstString.toShort();
    return shortNumber;
}
/**
 * @brief Converter::fromConstChar2String
 * @param pConstChar
 * @return STDString;
 * Conversión de const char* a std::string
 */
std::string Converter::fromConstChar2String(const char *pConstChar)
{
    std::string STDString(pConstChar);
    return STDString;
}
/**
 * @brief Converter::fromStringToQString
 * @param pSTDString
 * @return
 * Conversion de std::string a QString
 */
QString Converter::fromStringToQString(const std::string &pSTDString)
{
    QString qstrData(pSTDString.c_str()); // donde qstr es el QString
    return qstrData;
}

/**
 * @brief Converter::FromStringToConstChar
 * @param pDecimalNumber
 * @return constChar
 * Conversión de std::string a const char*
 */
const char* Converter::fromStringToConstChar(const std::string &pSTDString)
{
    const char* constChar = pSTDString.c_str();
    return constChar;
}

/**
 * @brief Converter::decimalToBinary
 * Convierte números (cadenas de strings) de una base a otra
 */
std::string Converter::decimalToBinary(const std::string &pDecimalNumber)
{
    std::string str(pDecimalNumber);   // Convert from std::string 2 Qstring
    QString qstrDecimalNumber(str.c_str());     // donde qstr es el QString
    //qDebug() << qstrDecimalNumber; // << qDebugendl;      // número decimal
    bool ok = false;
    //  convierte un string de decimal a binario
    QString binaryNumber =
        QString::number(qstrDecimalNumber.toLongLong(&ok, 10), 2);

    std::string stringBinary = binaryNumber.toStdString();
    stringBinary.length() == 8 ? stringBinary : completeBinary(stringBinary);
    //cout << "Conversión entero " << completeBinary( stringBinary ) << endl;
    return completeBinary(stringBinary);

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
    //qDebug() << qstrDecimalNumber; // número decimal
    bool ok = false;
    QString decimalNumber =
        QString::number(qstrDecimalNumber.toLongLong(&ok, 2), 10);
    //qDebug() << decimalNumber; // número convertido a decimal
    std::string stringDecimal = decimalNumber.toStdString();
    //cout << "Conversión de " << pBinaryString << " a " << stringDecimal << endl;
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
    //cout << "Conversión : " << completeBinary( string ) << endl;
    return completeBinary(string);    //string;
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
    //cout << "Conversión de " << pBinaryString << " a " << result << endl;
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

std::string Converter::completeBinary(std::string pBinary)
{
    short length = pBinary.length();
    if (length == getFillData()) {
        return pBinary;     // si no hay variación de tamaño
    } else {
        std::string complete = "0";
        for (int i = 0; i < ((getFillData() - 1) - length); ++i) {
            complete += "0";
        }
        complete += pBinary;
        //cout << complete << endl;
        return complete;
    }
}

/**
 * @brief Converter::fromString2Double
 * @param pDoubleString
 * @return
 * Funcion que convierte un std::string a double
 */
double Converter::fromString2Double(std::string pDoubleString)
{
    double doubleNumber = ::atof(pDoubleString.c_str());
    return doubleNumber;
}

/**
 * @brief Converter::fromDouble2String
 * @param pDoubleNumber
 * @return
 * Funcion que convierte un double a std::string
 */
std::string Converter::fromDouble2String(double pDoubleNumber)
{
    QString QstrDouble = QString::number(pDoubleNumber);
    std::string pDoubleString = QstrDouble.toStdString();
    //cout << pDoubleString << endl;
    return pDoubleString;
}

//http://forums.codeguru.com/showthread.php?482074-Binary-String-to-Double-Conversion
/**
 * @brief Converter::fromBinaryDouble2String
 * @param pDoubleString
 * @return
 * Función que convierte un std::string Double BINARIO a Double std::string
 */
std::string Converter::fromBinaryDouble2String(std::string pDoubleString)
{
    std::bitset<64> Bitset64(pDoubleString);
    double doubleNumber = Bitset64.to_ulong();
    //cout << doubleNumber << endl;
    return fromDouble2String(doubleNumber);
}

/**
 * @brief Converter::fromDoubleString2BinaryString
 * @param pDoubleString
 * @return
 * Funcion para convertir un string double en string binario
 * Por ej: 7.3 -> 73 (01001001) y contador - 1 (00000001) que es cantidad
 * de espacios después del punto 10 ** (contador - 1)
 */
std::string Converter::fromDoubleString2BinaryString(std::string pDoubleString)
{
    std::string entero;
    std::string decimal;
    for (int i = pDoubleString.find(".") + 1; i < pDoubleString.length() ; i++) {
        decimal += pDoubleString.at(i);
    }
    for (int j = 0; j < pDoubleString.find("."); j++) {
        entero += pDoubleString.at(j);
    }
    cout << decimal << endl;
//    cout << entero << endl;
    std::string decimalBinario = decimalToBinary(decimal);
//    cout << decimalBinario << endl;
    std::string enteroBinario = decimalToBinary(entero);
//    cout << enteroBinario << endl;
    setFillData(8); // se debe setear el valor para obtener una misma cantidad en los numeros
    cout << completeBinary(enteroBinario) + completeBinary(decimalBinario) << endl;
    return completeBinary(enteroBinario) + completeBinary(decimalBinario) ;      //entero + decimal;
}

/**
 * @brief Converter::fromBinaryString2DoubleString
 * @param pBinaryString
 * @return
 * Función para convertir desde string binario a string Double
 */
std::string Converter::fromBinaryString2DoubleString(std::string pDoubleBinaryString)
{
    std::string decimal;
    std::string entero;
    // conversion parte entera
    for (int i = (pDoubleBinaryString.length() / 2); i < pDoubleBinaryString.length(); i++) {
        decimal += pDoubleBinaryString.at(i);
    }
    cout << decimal << endl;
    cout << binaryToDecimal(decimal) << endl;
    for (int i = 0; i < (pDoubleBinaryString.length() / 2) ; i++) { // conversion parte entera
        entero += pDoubleBinaryString.at(i);
    }
    cout << entero << endl;
    cout << binaryToDecimal(entero) << endl;

    cout << binaryToDecimal(entero) + "." + binaryToDecimal(decimal) << endl;
    //cout << fromDouble2String( final ) << endl;
    return binaryToDecimal(entero) + "." + binaryToDecimal(decimal);
}

std::string Converter::fromInt2String(int pIntNumber)
{
    std::string stringIntNumber = std::to_string(pIntNumber);
    return stringIntNumber;
}

/**
 * @brief Converter::fromString2Int
 * @param pIntString
 * @return
 * Conversión de std::string a int
 */
int Converter::fromString2Int(std::string pIntString)
{
    int intNumber = atoi(pIntString.c_str());
    //cout << intNumber << endl;
    return intNumber;
}


/**
 * @brief Converter::verificaValidezInt
 * @param pDato
 * @return
 * Función que indica si un string es un entero (true) o son letras (false)
 */
bool Converter::verificaValidezInt(QString pDato)
{
    bool charValido;
    int validaIntroduceNumeros;
    for (int i = 0; i < pDato.length() ; i++) {
        //validacion de que solo se introducen numeros(convierten qstring a int)
        validaIntroduceNumeros = pDato.toInt(&charValido);
        if (charValido == false) {  //existe un caracter que no es número
            return false;
        }//fin del if interno
        else {
            return true;
        }//fin if
    }//fin del for
}

/**
 * @brief Converter::verificaValidezDouble
 * @param pDato
 * @return
 * Función que indica si un string es un double (true) o son letras o entero (false)
 */
bool Converter::verificaValidezDouble(QString pDato)
{
    bool charValido;
    double validaIntroduceNumeros;
    if (!verificaValidezInt(pDato)) {       // si no es string(numero entero)
        for (int i = 0; i < pDato.length() ; i++) {
            //validacion de que solo se introducen numeros(convierten qstring a int)
            validaIntroduceNumeros = pDato.toDouble(&charValido);
            if (charValido == false) {  //existe un caracter que no es número
                // cout << "No es double! " << validaIntroduceNumeros << endl;
                return false;
            }//fin del if interno
            else {
                //cout << "Es un double! " << validaIntroduceNumeros << endl;
                return true;
            }//fin if
        }//fin del for
    } else {
        //cout << "Es numero entero" << endl;
        return false;   // pues es un numero entero
    }
}
