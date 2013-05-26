#include <QFile>
#include <QDebug>

int ex1()
//int main()
{
    QFile file("RAIDB.pro");

    if (!file.open(QIODevice::ReadOnly)) {
        return 0;
    }

    QByteArray blob = file.readAll();

    qDebug() << file.size() << endl;
    qDebug() << "----------------------------" << endl;
    qDebug() << blob << endl;
    qDebug() << "----------------------------" << endl;
    qDebug() << file.error() << endl;

    file.close();

    return 0;
}
