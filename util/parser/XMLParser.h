/*******************************************************************************
 * File: XMLParser.h
 * Author: Daniel Araya
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <iostream>
#include <QtXml/QDomDocument>
#include <QStandardItem>
#include <QFile>
#include <QString>
#include <QDebug>
#include "dataStructure/IN_aryNode.h"
#include "IParser.h"

using namespace std;

class XMLParser: public IParser{

private:
    QString _pathXMLFile;       // Archivo XML a leer PRUEBA
    QString _wpathXMLFile;      // Archivo XML a escribir PRUEBA
    QString _pathBACKUP;        // Archivo XML del Back Up
//    QDomDocument _documento;
//    QDomElement _xmlraiz;       // Crea un nodo root
//    QDomElement _xmlraiztmp;       // Crea un nodo root
//    QDomElement _xmlNewCarpet;

public:
    XMLParser();        // Constructor
    ~XMLParser();       // Destructor

// ----- MÉTODOS DE LA INTERFAZ IPARSER -----
    virtual void generateBackUp(unsigned short pAmountDisks,
                     unsigned short pAmountDiskGroups,
                     unsigned short pAmountUsers);  // Crea un XML
    virtual void readFile();    // Lee un XML PRUEBA
    virtual void writeFile();   // Escribe un XML PRUEBA

};

#endif // XMLPARSER_H
