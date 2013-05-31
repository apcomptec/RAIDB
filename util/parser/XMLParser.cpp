#include "XMLParser.h"

//  http://www.youtube.com/watch?v=IrFOM0azfxQ

XMLParser::XMLParser()
{
    this->_pathXMLFile = "doc/PruebaReadRegistro.xml";
    this->_wpathXMLFile = "doc/PruebaWriteRegistro.xml";
}

/**
 * @brief XMLParser::readFile
 * Lee un XML
 */
void XMLParser::readFile()
{
    QStandardItem *root = new QStandardItem( "Blocks" );
    QDomDocument document;
    QFile file( _pathXMLFile );
    if( file.open(QIODevice::ReadOnly | QIODevice::Text) ){
        document.setContent( &file );
        file.close();
    }
    // obtiene del xml el root
    QDomElement xmlroot = document.firstChildElement();
   // lee records
    QDomNodeList records = xmlroot.elementsByTagName( "Record" );
    for (int i = 0; i < records.count(); i++){
        QDomElement record = records.at(i).toElement();
        //Record ID="1" Parent="0" LeftChild="2" RightChild="3" int="11" char="a" string="daniel1" bool="0"/>
        QStandardItem *ID = new QStandardItem(record.attribute("ID"));
        QStandardItem *Parent = new QStandardItem(record.attribute("Parent"));
        QStandardItem *LeftChild = new QStandardItem(record.attribute("LeftChild"));
        QStandardItem *RightChild = new QStandardItem(record.attribute("RightChild"));
        qDebug() << " Record # " << ID->text() << "  "
                 << " Parent " << Parent->text() << "  "
                 << " LeftChild " << LeftChild->text() << "  "
                 << " RightChild " << RightChild->text() << endl;
        // se obtiene un subnodo y hay q iterar
        //QDomNodeList varas = xmlroot.elementsByTagName( "Varas" );

        //recordItem->appendRow(varas); forma el arbol xml
    root->appendRow( ID );
    }
}

/**
 * @brief XMLParser::writeFile
 * Escribe un XML
 */
void XMLParser::writeFile()
{
    QDomDocument document;
    // crea un nodo root
    QDomElement xmlroot = document.createElement("Blocks");
    document.appendChild(xmlroot);
    for ( int i = 0; i < 5; i++ ){
        QDomElement xmlRecord = document.createElement("Record");
        xmlRecord.setAttribute( "ID", i );
        xmlRecord.setAttribute( "Parent", 1.0 );
        xmlRecord.setAttribute( "RightChild", i );
        xmlRecord.setAttribute( "LeftChild", 1.0 );
        xmlroot.appendChild(xmlRecord);
    }
    // guardar archivo
    QFile file( _wpathXMLFile );
    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) ){
        qDebug() << "Error al guardar archivo";
    }
    QTextStream stream( &file );
    stream << document.toString();
    file.close();
    qDebug() << "Archivo Guardado";
}

void XMLParser::createFile()
{
    // crea un nodo root

}



/**
 * @brief XMLParser::~XMLParser
 * Destructor
 */
XMLParser::~XMLParser(){}




