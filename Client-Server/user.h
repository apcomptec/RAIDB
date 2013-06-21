#ifndef USER_H
#define USER_H
#include "QString"

/**
 * @brief The User class
 *  Clase usuario en la cual estaran los datos de cada uno
 *  para verificar y validar para que este se pueda conectar
 *  al servidor.
 */
class User
{
private:
    //Nombre de usuario
    QString _userName;
    //Constraseña del usuario
    QString _password;
    //Identificador de usuario
    int _id;

public:
    User(QString pUser, QString pPassword);
    ~User();

    //METODOS PARA OBTENER VARIABLES
    QString getUser() const;
    QString getPassword() const;
    int getID() const;

    //METODOS DE MODIFICACION DE VARIABLE
    void setUser(QString);
    void setPassword(QString);
    void setID(int);
};
//Fin de la clase
#endif // USER_H
