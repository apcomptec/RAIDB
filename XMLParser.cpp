#include "XMLParser.h"

XMLParser::XMLParser()
{
    this->_pathXMLFile = "planet.xml";
    this->_XMLfile = new QFile( _pathXMLFile );
}

XMLParser::~XMLParser(){}


void XMLParser::writeFile()
{
    QXmlStreamWriter xmlWriter;
    QFile file("output.xml");
    if (!file.open(QIODevice::WriteOnly)){
          cout << "Error opening file" << endl;
        }
    else{
        xmlWriter.setDevice(&file);

        /* Writes a document start with the XML version number. */
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("students");

        xmlWriter.writeStartElement("student");
        /*add one attribute and its value*/
        xmlWriter.writeAttribute("name","Kate");
        /*add one attribute and its value*/
        xmlWriter.writeAttribute("surname","Johns");
        /*add one attribute and its value*/
        xmlWriter.writeAttribute("number","154455");
        /*add character data to tag student */
        xmlWriter.writeCharacters ("Student 1");
        /*close tag student  */
        xmlWriter.writeEndElement();

            /*end tag students*/
        xmlWriter.writeEndElement();
            /*end document */
        //xmlWriter.writeEndDocument();
       }
}


void XMLParser::readFile()
{
}

