#include "ListClient.h"

ListClient::ListClient()
{
    this->_head=NULL;
    this->_tail=NULL;
    this->count=-1;

}
void ListClient::insertconnection(string pIP, int pPort){
    ClientNode *tmp;
    if(this->_head == NULL){
        this->_head = new ClientNode (pIP,pPort);
        this->count++;
    }
    else{
        tmp=this->_head;
        while(tmp->_Next !=NULL)
            tmp=tmp->_Next;

        tmp->_Next = new ClientNode(pIP,pPort);
       // this->count++;

        }
    this->count++;

    }
void ListClient::printconnection(){
    ClientNode * first;
    first= this->_head;
    int c=1;
    while(first != NULL){
       // cout << "IP:"+p->p<<"port:"+p->data<<"\n";
        cout<<c<<"Ip:"+first->_IP<<endl;
        cout<<c<<"Port:"<<first->_Port<<endl;

        first = first->_Next;
        c++;
        }
    }
ClientNode* ListClient::gethead(){
    return this->_head;
}
unsigned short ListClient::getcount(){
    return this->count;
}
void ListClient::setcount(unsigned short count){
    this->count+=count;
}


//int main(){

//    ListClient* p=new ListClient();
//    p->insertconnection("32234",4343);
//    p->insertconnection("fdfdfg",543543);
//    p->insertconnection("rere",4343);
//    p->insertconnection("wewerew",334242);
//    p->insertconnection("ewrerew",4343);
//    p->insertconnection("43333",4343);
//    p->insertconnection("ererer",34434);
//    p->printconnection();
//    return 0;

//}
