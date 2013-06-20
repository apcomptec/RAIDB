#include "Encryption.h"

Encryption::Encryption()
{
    this->_aleatorioNumeros = new RandomNumber( 65, 90 );
    this->_aleatorioLetrasM = new RandomNumber( 97, 122 );
    this->_aleatorioLetrasm = new RandomNumber( 48, 57 );
    this->_conversor = new Converter();
}

/**
 * @brief Encryption::passwordEncryption
 * @param pPassword
 * @return una clave encriptada
 */
std::string Encryption::passwordEncryption( std::string pPassword )
{
    QByteArray loginPassword = pPassword.c_str();
    QString qEncrytedPassword = QString(QCryptographicHash::hash(( loginPassword ),
                           QCryptographicHash::Md5).toHex());

    cout << "Enciptado es: " << qEncrytedPassword.toStdString() << endl;
    return qEncrytedPassword.toStdString();
}

/**
 * @brief Encryption::generateRandomPassword
 * @return Clave aleatoria sin encriptar
 */
string Encryption::generateRandomPassword()
{
    string clave;
    unsigned short value;
    int choose;
    for (unsigned short i = 0; i < 64; i++){
        choose = 1 + (rand() % 3);//escoge numeros de 1 a 3
        if(choose == 1){
            value = _aleatorioNumeros->generateRandom();}
        else if(choose == 2){
            value = _aleatorioLetrasM->generateRandom();}
        else if(choose == 3){
            value = _aleatorioLetrasm->generateRandom();}
        else{
            value = _aleatorioNumeros->generateRandom();}
        //cout << "Value Generada: " << value << endl;
        clave += generateRandomPasswordAUX( value );
    }
    cout << "Clave Generada: " << clave << endl;
    cout << "Tamaño Clave Generada: " << clave.length() << endl;
    return clave;
}

/**
 * @brief Encryption::generateRandomPasswordAUX
 * @param pValue
 * Conversión de int a ascii
 * @return
 */
std::string Encryption::generateRandomPasswordAUX( unsigned short pValue )
{
    QString finalValue = QChar( pValue );     // conversión de int a ascii
    return finalValue.toStdString();
}




////An UTF8 encoded QByteArray
//QByteArray aByteArray = aString.c_str();

////From an UTF8 encoded QByteArray to a QString
//QString aQString = QString::fromUtf8(aByteArray.data(), aByteArray.size());









