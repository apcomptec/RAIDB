#include "Converter.h"

Converter::Converter()
{
}


/**
 * @brief Converter::decimal2Binary
 * Convierte números (cadenas de strings) de una base a otra
 */
QString Converter::decimal2Binary( std::string pDecimalNumber )
{
    std::string str( pDecimalNumber ); // Convert from std::string 2 Qstring
    QString qstrDecimalNumber( str.c_str() );   // donde qstr es el QString
    qDebug() << qstrDecimalNumber << endl;      // número decimal

    bool ok = false;
    //  convierte un string de decimal a binario
    QString binaryNumber = QString::number(qstrDecimalNumber.toLongLong(&ok, 10), 2);
    qDebug() << binaryNumber << endl;  // "111"
    return binaryNumber;

}

/**
 * @brief Converter::binary2Decimal
 * @param pBinaryString
 * Convierte números de binario a decimal
 */
QString Converter::binary2Decimal( std::string pBinaryString )
{
    std::string str( pBinaryString ); // Convert from std::string 2 Qstring
    QString qstrDecimalNumber( str.c_str() );   // donde qstr es el QString
    qDebug() << qstrDecimalNumber << endl;      // número decimal

    bool ok = false;
    QString decimalNumber = QString::number(qstrDecimalNumber.toLongLong(&ok, 2), 10);
    qDebug() << decimalNumber << endl;  // numero convertido a decimal
    return decimalNumber;
}

/**
 * @brief Converter::string2Binary
 * @param pStringLetters
 * Función para convertir std::string a binario
 */
void Converter::string2Binary( std::string pStringLetters )
{
    cout << pStringLetters << endl;
    for ( std::size_t i = 0; i < pStringLetters.size(); ++i){
        cout << bitset<8>(pStringLetters.c_str()[i]) << endl;
    }


}

void Converter::binary2String( std::string pBinaryString )
{

}
