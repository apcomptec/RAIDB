//#include <QtCore/QCoreApplication>
//#include "client.h"

//int mainClient(int argc, char *argv[])
////int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//    QString ip ("172.26.105.190");
//    Client c;
//    c.connectToServer(ip, 9999);
//    return a.exec();
//}



//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
#include "client.h"
#include "ListClient.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client c;


   // c.connectToServer("172.26.102.118", 1234);
   // c.connectToServer("172.26.102.6", 1234);
    c.ListAllconnection("172.26.102.219",1234);
//    cout<<"puta"<<endl;
    c.ListAllconnection("172.26.102.6",1234);


    c.ConnectToAllserver();
      return a.exec();

}

//int main(){
//    ListClient* p=new ListClient();
//    p->insertconnection("dsds",43434);
//    p->insertconnection("4343",44343);
//    p->insertconnection("dsdfsdfdsf",44343);
//    p->insertconnection("sdfsfs",34534);
//    p->printconnection();
//}
