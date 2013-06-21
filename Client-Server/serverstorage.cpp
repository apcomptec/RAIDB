#include "serverstorage.h"

ServerStorage::ServerStorage()
{
}
ServerStorage::~ServerStorage()
{}

/**
 * @brief Server::incomingConnection
 *  Metodo para recibir las conexiones entrantes
 *  usando hilos de ejecucion y hacer que sea multi
 *  -client.
 * @param pSocketDescriptor
 */
void ServerStorage::incomingConnection(int pSocketDescriptor)
{
    qDebug() << pSocketDescriptor << "Conectando...";

    //Se inicializa un hilo de ejecucion
   this->thread = nullptr;

    //Conectar el socket mediante el hilo de ejecucion
    connect(this->thread, SIGNAL(finished()), this->thread,SLOT(deleteLater()));
    //El hilo empieza a ejecutar
    this->thread->start();
}
