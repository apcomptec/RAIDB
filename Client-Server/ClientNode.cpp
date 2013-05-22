#include "ClientNode.h"

ClientNode::ClientNode(string pIP, int pPort)
{
    this->_IP=pIP;
    this->_Port=pPort;
    this->_Next=NULL;
    this->_Previous=NULL;
}
string ClientNode::getIP(){
    return this->_IP;
}
ClientNode *ClientNode::getnext(){
    return this->_Next;
}
int ClientNode::getPort(){
    return this->_Port;
}
ClientNode *ClientNode::getprevious(){
    return this->_Previous;
}
void ClientNode::setIP(string pIP){
    this->_IP=pIP;
}
void ClientNode::setnext(ClientNode *pNext){
    this->_Next=pNext;
}
void ClientNode::setPort(int pPort){
    this->_Port=pPort;
}
void ClientNode::setprevious(ClientNode *pPrevious){
    this->_Previous=pPrevious;
}
