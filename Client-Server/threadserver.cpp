#include "threadserver.h"

/**
 * @brief ThreadServer::ThreadServer
 *  Constructor del hilo de ejecucion
 * @param ID
 * @param parent
 */
ThreadServer::ThreadServer(int ID, QObject *parent) :
    QThread(parent)
{
    //Se identifica el hilo
    this->_socketDescriptor = ID;
}

/**
 * @brief ThreadServer::run
 *  Metodo de ejecucion del hilo.
 */
void ThreadServer::run(){
    //El hilo empieza a ejecutar
    qDebug() << "Inicio del hilo";

    //Se inicializa el hilo de ejecucion
    this->_socket  = new QTcpSocket();

    if(!this->_socket->setSocketDescriptor(this->_socketDescriptor))
    {
        emit error(this->_socket->error());
        return;
    }

    //Se conecta el socket y empieza a leer los datos
    connect(this->_socket, SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(this->_socket, SIGNAL(disconnected()),this,SLOT(disconnect()),Qt::DirectConnection);

    qDebug() << this->_socketDescriptor << " Client connected";

    exec();
}

/**
 * @brief ThreadServer::readyRead
 *  Metodo para empezar a leer los datos
 *  enviados al socket.
 */
void ThreadServer::readyRead()
{
    //Array de datos
    QByteArray Data = this->_socket->readAll();


    qDebug() << this->_socketDescriptor << "Data in: " << Data;

    this->answerProtocol("true");

}

void ThreadServer::answerProtocol(QString pMessage)
{
    //Se escribe en el socket
    try{
        this->_socket->write((pMessage+"\n").toAscii());
    }catch(char e){
        qDebug() << e;
    }

    while(_socket->flush())
    {
        qDebug() << "Flush";
    }
}


/**
 * @brief ThreadServer::disconnect
 *  Metodo para desconectar el socket
 */
void ThreadServer::disconnect()
{
    qDebug() << this->_socketDescriptor << "Client disconnected";
    //Se elimina el socket temporalmente
    this->_socket->deleteLater();
    exit(0);
}
