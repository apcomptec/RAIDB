#include "masterthread.h"

MasterThread::MasterThread(int &pID, QObject* parent)
{
    this->_socketDescriptor = pID;
    this->_listUser = new DLL<User*>();
}

MasterThread::~MasterThread()
{}

void MasterThread::answerProtocol(QString pMessage)
{
    QRegExpValidator validator;
    int pos = 0;
    QRegExp connect ("connect[0-9A-ZñÑa-z:/. ]{10,256}");
    validator.setRegExp(connect);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Usuario Conectado";
        this->writeToClient(this->verifyUser(pMessage));
        return;
    }
    qDebug() << validator.validate(pMessage, pos);
    QRegExp adduser ("adduser[0-9A-ZñÑa-z:/. ]{10,256}");
    validator.setRegExp(adduser);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Usuario incluido";
        this->writeToClient(this->addUser(pMessage));
        return;
    }
    QRegExp get ("get[A-ZñÑa-z// ]{5,256}");
    validator.setRegExp(get);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se envio el archivo";
        this->writeToClient("true");
        return;
    }
    QRegExp cd ("cd[A-ZñÑa-z ]{10,256}");
    validator.setRegExp(cd);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se movio de carpeta";
        this->writeToClient("true");
        return;
    }
    QRegExp touch ("touch[A-ZñÑa-z#/-// ]{10,256}");
    validator.setRegExp(touch);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se crea archivo";
        this->writeToClient("true");
        return;
    }
    QRegExp rm ("rm[A-ZñÑa-z// ]{10,256}");
    validator.setRegExp(rm);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Archivo o carpeta removida";
        this->writeToClient("true");
        return;
    }
    QRegExp openfile ("openfile[A-ZñÑa-z// ]{10,256}");
    validator.setRegExp(openfile);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Archivo abierto";
        this->writeToClient("true");
        return;
    }
    QRegExp appendReg ("appendReg[0-9A-ZñÑa-z ]{10,256}");
    validator.setRegExp(appendReg);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Registro añadido";
        this->writeToClient("true");
        return;
    }
    QRegExp delReg ("delReg[0-9A-ZñÑa-z ]{10,256}");
    validator.setRegExp(delReg);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Registro removido";
        this->writeToClient("true");
        return;
    }
    QRegExp write ("write[0-9A-ZñÑa-z ]{10,256}");
    validator.setRegExp(write);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se modifica registro";
        this->writeToClient("true");
        return;
    }
    QRegExp seek ("seek[0-9A-ZñÑa-z ]{1,256}");
    validator.setRegExp(seek);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se mueve puntero";
        this->writeToClient("true");
        return;
    }
    QRegExp read ("read[0-9A-ZñÑa-z ]{1,256}");
    validator.setRegExp(read);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se lee registro";
        this->writeToClient("true");
        return;
    }
    QRegExp close ("close[a-z]{0,10}");
    validator.setRegExp(close);
    if(validator.validate(pMessage, pos) == 2)
    {
        qDebug() << "Se cierra el cliente";
        this->writeToClient("true");
        return;
    }
    this->writeToClient("false");
}

QString MasterThread::verifyUser(QString pMessage)
{
    QRegExp regex ("[:]");
    QString user = pMessage.split(regex)[2];
    QString password = pMessage.split(regex)[3];

    DLLNode<User*>* userNode = this->_listUser->getHeadPtr();
    while(userNode != nullptr && userNode->getData()->getUser() != user)
    {
        userNode = userNode->getNextPtr();
    }

    if(userNode == nullptr)
    {
        return "false";
    }
    else if(userNode->getData()->getUser() == user && userNode->getData()->getPassword() == password)
    {
        return "true";
    }else
    {
        return "false";
    }
}

QString MasterThread::addUser(QString pMessage)
{
    QRegExp regex ("[:]");
    QString user = pMessage.split(regex)[2];
    qDebug() << "User: " << user;
    QString password = pMessage.split(regex)[3];
    qDebug() << "Password: " << password;

    DLLNode<User*>* userNode = this->_listUser->getHeadPtr();
    while(userNode != nullptr && userNode->getData()->getUser() != user)
    {
        userNode = userNode->getNextPtr();
    }
    if(userNode == nullptr)
    {
        User* newUser = new User(user,password);
        this->_listUser->insertAtBack(newUser);
        return "true";
    }else{
        return "false";
    }
}
