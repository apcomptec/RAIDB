#include "user.h"

/**
 * @brief User::User
 *  Constructor de la clase usuario
 * @param pUser
 * @param pPassword
 */
User::User(QString pUser, QString pPassword)
{
    this->_userName = pUser;
    this->_password = pPassword;
}

/**
 * @brief User::~User
 *  Destructor
 */
User::~User()
{
}

/**
 * @brief User::getUser
 * @return
 */
QString User::getUser() const
{
    return this->_userName;
}
/**
 * @brief User::getPassword
 * @return
 */
QString User::getPassword() const
{
    return this->_password;
}

/**
 * @brief User::getID
 * @return
 */
QString User::getID() const
{
    return this->_ip;
}

/**
 * @brief User::setUser
 * @param pUser
 */
void User::setUser(QString pUser)
{
    this->_userName = pUser;
}

/**
 * @brief User::setPassword
 * @param pPassword
 */
void User::setPassword(QString pPassword)
{
    this->_password = pPassword;
}

/**
 * @brief User::setID
 * @param pID
 */
void User::setID(QString pID)
{
    this->_ip = pID;
}
