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
    QString _pathXMLFile;       // Archivo XML a leer
    QString _wpathXMLFile;      // Archivo XML a escribir
    QString _pathBACKUP;        // Archivo XML del Back Up
//    QDomDocument _documento;
//    QDomElement _xmlraiz;       // Crea un nodo root
//    QDomElement _xmlraiztmp;       // Crea un nodo root
//    QDomElement _xmlNewCarpet;

public:
    XMLParser();        // Constructor
    ~XMLParser();       // Destructor

// ----- MÉTODOS DE LA INTERFAZ IPARSER -----
    virtual void createFile();  // Crea un XML
    void createFile1(unsigned short pAmountDisks,
                     unsigned short pAmountDiskGroups,
                     unsigned short pAmountUsers);  // Crea un XML
    void writeFileData( QString pPath );
    void saveFile();
    virtual void readFile();    // Lee un XML
    virtual void writeFile();   // Escribe un XML

};

#endif // XMLPARSER_H
