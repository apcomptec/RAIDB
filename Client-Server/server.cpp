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
