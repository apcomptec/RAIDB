#include "server.h"

/**
 * @brief Server::Server
 *  Constructor
 * @param parent
 */
Server::Server(QObject *parent) :
    QTcpServer(parent)
{
}


/**
 * @brief Server::startServer
 *  Metodo que inicializa el servidor mediante un puerto esppecifico
 */
void Server::startServer()
{
    //Se verifica que se haya inicializado el socket de escucha
    if(!this->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "No se pudo iniciar el servidor";
    }
    else
    {
        qDebug() << "Escuchando..." ;
    }
}

/**
 * @brief Server::incomingConnection
 *  Metodo para recibir las conexiones entrantes
 *  usando hilos de ejecucion y hacer que sea multi
 *  -client.
 * @param pSocketDescriptor
 */
void Server::incomingConnection(int pSocketDescriptor)
{
    qDebug() << pSocketDescriptor << "Conectando...";
    //Se inicializa un hilo de ejecucion
    ThreadServer *thread = new ThreadServer(pSocketDescriptor);

    //Conectar el socket mediante el hilo de ejecucion
    connect(thread, SIGNAL(finished()), thread,SLOT(deleteLater()));
    //El hilo empieza a ejecutar
    thread->start();
}
