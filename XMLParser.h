#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <iostream>
#include <QtXml/QDomDocument>
#include <QStandardItem>
#include <QFile>
#include <QString>
#include <QDebug>
#include "IParser.h"

using namespace std;

class XMLParser: public IParser{

private:
    QString _pathXMLFile;       // Archivo XML a leer
    QString _wpathXMLFile;      // Archivo XML a escribir

public:
    XMLParser();        // Constructor
    ~XMLParser();       // Destructor

// ----- MÉTODOS DE LA INTERFAZ IPARSER -----
    virtual void createFile();  // Crea un XML
    virtual void readFile();    // Lee un XML
    virtual void writeFile();   // Escribe un XML

};

#endif // XMLPARSER_H
