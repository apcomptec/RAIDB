#include "Encryption.h"

Encryption::Encryption()
{
}

std::string Encryption::passwordEncryption( std::string pPassword )
{
    QByteArray loginPassword = pPassword.c_str();
    QString qEncrytedPassword = QString(QCryptographicHash::hash(( loginPassword ),
                           QCryptographicHash::Md5).toHex());

    cout << "Enciptado es: " << qEncrytedPassword.toStdString() << endl;
    return qEncrytedPassword.toStdString();
}


////An UTF8 encoded QByteArray
//QByteArray aByteArray = aString.c_str();

////From an UTF8 encoded QByteArray to a QString
//QString aQString = QString::fromUtf8(aByteArray.data(), aByteArray.size());
