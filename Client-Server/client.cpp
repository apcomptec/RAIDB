
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
//    socket = new QTcpSocket(this);
////    //Se conecta el socket
//    connect(socket, SIGNAL(connected()),
//            this, SLOT(on_connected()));
//    connect(socket, SIGNAL(connected()),
//            this,SLOT(ConnectToAllserver()));

    this->Listconnection=new ListClient();

}

/**
 * @brief Client::on_connected
 *  Metodo para enviar mensajes mediante el socket,
 *  mantiene abierto el canal para envio.
 */
//void Client::on_connected()
//{




//    std::cout << ("Connection established.\n");
//    //Buffer de envio
//    char buffer[1024];
//    //Ciclo de envio
//    forever
//    {
//        std::cout << (">> ");
//        //Se obtiene el buffer a enviar desde consola
//        gets(buffer);
//        //Tamaño de buffer
//        int len = strlen(buffer);
//        buffer[len] = '\n';
//        buffer[len+1] = '\0';
//        //Se es








//escribe en el socket
//        socket->write(buffer);
//        socket->flush();




//    }

//}

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
void Client::ListAllconnection(string pIP, int pPort){

    this->Listconnection->insertconnection(pIP,pPort);
    cout<<"puta"<<endl;
}
void Client::ConnectToAllserver(){

  //  cout<<"puta"<<endl;
    ClientNode* tmp=this->Listconnection->gethead();


    cout<<"puta"<<endl;

    while(tmp!=NULL){



         std::string Ip =tmp->getIP() ;
         QString qstr = QString::fromStdString(Ip);
         int Port=tmp->getPort();



    try{


            socket = new QTcpSocket(this);
             //Se conecta el socket
            connect(socket, SIGNAL(connected()),
                     this,SLOT(ConnectToAllserver()));

             QHostAddress address(qstr);

             //Conectarse al socket
             socket->connectToHost(address, Port);
             std::cout << ("Connection established.\n");
             //Buffer de envio

             char buffer[1024];
             //Ciclo de envio

                 std::cout << (">> ");
                 //Se obtiene el buffer a enviar desde consola
                 gets(buffer);
                 //Tamaño de buffer
                 int len = strlen(buffer);
                 buffer[len] = '\n';
                 buffer[len+1] = '\0';
                 //Se escribe en el socket
                 cout<<"escriba"<<endl;
                 //socket->write(buffer);
                 socket->write(buffer);


                 cout<<"envia"<<endl;




                 // socket->flush();


                //socket->flush();
               //socket->close();





            // cout<<Ip<<endl;




         }catch(int i){
             cout << " Error capturado --su valor es: ";
                 cout << i << "\n";

          }
//         cout<<"dos"<<endl;
//         cout<<this->Listconnection->getcount()<<endl;
//         cout<<count2<<endl;
//         if (this->Listconnection->getcount()==count2)
//         {
//         tmp=this->Listconnection->gethead();
//         this->Listconnection->setcount(global);

//          }
//         else{
//         cout<<tmp->_IP<<endl;

//         tmp=tmp->getnext();
//         // cout<<tmp->_IP<<endl;
//         }

           tmp=tmp->getnext();

     }
 }

