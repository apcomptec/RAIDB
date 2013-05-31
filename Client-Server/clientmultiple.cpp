#include "clientmultiple.h"

ClientMultiple::ClientMultiple()
{
    _list = new DLL<Client*>();
}

void ClientMultiple::addIPAdrress(QString pIP, int pPort)
{
    Client* client = new Client();
    client->connectToServer(pIP, pPort);
    this->_list->insertAtBack(client);
}

void ClientMultiple::start()
{
    printf("Connection established.\n");
    char buffer[1024];
    DLLNode<Client*>* tmpNode = this->_list->getHeadPtr();
    forever
    {
        printf(">> ");
        gets(buffer);
        for (int i = 0; i < _list->getSize(); ++i) {
            tmpNode->getData()->on_connected(buffer);
            tmpNode = tmpNode->getNextPtr();
        }
        tmpNode = this->_list->getHeadPtr();
    }
}
