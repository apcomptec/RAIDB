#include "client.h"


/**
 * @brief Client::Client
 *  Constructor de la clase
 * @param parent
 */
Client::Client(QObject *parent) :
    QObject(parent)
{
    //Se inicializa el socket de escucha
    socket = new QTcpSocket(this);
    //Se conecta el socket
    connect(socket, SIGNAL(connected()),
            this, SLOT(on_connected()));
}

/**
 * @brief Client::on_connected
 *  Metodo para enviar mensajes mediante el socket,
 *  mantiene abierto el canal para envio.
 */
void Client::on_connected()
{
    std::cout << ("Connection established.\n");
    //Buffer de envio
    char buffer[1024];
    //Ciclo de envio
    forever
    {
        std::cout << (">> ");
        //Se obtiene el buffer a enviar desde consola
        gets(buffer);
        //Tamaño de buffer
        int len = strlen(buffer);
        buffer[len] = '\n';
        buffer[len+1] = '\0';
        //Se escribe en el socket
        socket->write(buffer);
        socket->flush();
    }

}

/**
 * @brief Client::connectToServer
 *  Metodo para conectar al servidor mediante ip y puerto
 * @param pIp
 */
void Client::connectToServer(QString pIp, int pPort)
{
    //Convertir la ip de string a una direccion
    QHostAddress address(pIp);
    //Conectarse al socket
    socket->connectToHost(address, pPort);
}
