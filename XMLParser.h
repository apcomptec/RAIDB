#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <iostream>
#include <QtXml/QDomDocument>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <QDebug>

using namespace std;

class XMLParser{

private:
    QFile *_XMLfile;
    QString _pathXMLFile;
    QXmlStreamReader *_XMLReader;

public:
    XMLParser();
    ~XMLParser();
    void initXMLParserProcess();
    void createFile();
    void readFile();
    void writeFile();

};

#endif // XMLPARSER_H
