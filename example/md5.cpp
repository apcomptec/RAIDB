#include <iostream>
#include <QString>
#include <QCryptographicHash>

int md5()
{
    QString blah = QString(QCryptographicHash::hash(("jejeje"),
                           QCryptographicHash::Md5).toHex());

    std::cout << blah.toStdString() << std::endl;

    return 0;
}
