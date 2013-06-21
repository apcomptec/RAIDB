#include "masterthread.h"

MasterThread::MasterThread(int &pID, QObject* parent)
{
    this->_socketDescriptor = pID;
}

MasterThread::~MasterThread()
{}

void MasterThread::answerProtocol(QString pMessage)
{
    QRegExpValidator validator;
    int pos = 0;
    QRegExp connect ("connect[A-ZñÑa-z ]{10,256}");
    validator.setRegExp(connect);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Usuario Conectado";
        this->writeToClient("true");
        return;
    }
    qDebug() << validator.validate(pMessage, pos);
    QRegExp adduser ("adduser[A-ZñÑa-z ]{10,256}");
    validator.setRegExp(adduser);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Usuario incluido";
        this->writeToClient("true");
        return;
    }
    QRegExp get ("get[A-ZñÑa-z// ]{5,256}");
    validator.setRegExp(get);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se envio el archivo";
        this->writeToClient("true");
        return;
    }
    QRegExp cd ("cd[A-ZñÑa-z ]{10,256}");
    validator.setRegExp(cd);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se movio de carpeta";
        this->writeToClient("true");
        return;
    }
    QRegExp touch ("touch[A-ZñÑa-z#/-// ]{10,256}");
    validator.setRegExp(touch);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se crea archivo";
        this->writeToClient("true");
        return;
    }
    QRegExp rm ("rm[A-ZñÑa-z// ]{10,256}");
    validator.setRegExp(rm);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Archivo o carpeta removida";
        this->writeToClient("true");
        return;
    }
    QRegExp openfile ("openfile[A-ZñÑa-z// ]{10,256}");
    validator.setRegExp(openfile);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Archivo abierto";
        this->writeToClient("true");
        return;
    }
    QRegExp appendReg ("appendReg[0-9A-ZñÑa-z ]{10,256}");
    validator.setRegExp(appendReg);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Registro añadido";
        this->writeToClient("true");
        return;
    }
    QRegExp delReg ("delReg[0-9A-ZñÑa-z ]{10,256}");
    validator.setRegExp(delReg);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Registro removido";
        this->writeToClient("true");
        return;
    }
    QRegExp write ("write[0-9A-ZñÑa-z ]{10,256}");
    validator.setRegExp(write);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se modifica registro";
        this->writeToClient("true");
        return;
    }
    QRegExp seek ("seek[0-9A-ZñÑa-z ]{1,256}");
    validator.setRegExp(seek);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se mueve puntero";
        this->writeToClient("true");
        return;
    }
    QRegExp read ("read[0-9A-ZñÑa-z ]{1,256}");
    validator.setRegExp(read);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se lee registro";
        this->writeToClient("true");
        return;
    }
    QRegExp close ("close[a-z]{0,10}");
    validator.setRegExp(close);
    qDebug() << validator.validate(pMessage, pos);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se cierra el cliente";
        this->writeToClient("true");
        return;
    }
    this->writeToClient("false");
}
