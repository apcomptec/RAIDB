#include "XMLParser.h"

//  http://www.youtube.com/watch?v=IrFOM0azfxQ

XMLParser::XMLParser()
{
    this->_pathXMLFile = "/home/darayavilla/Qt_projects/Proyecto2/apcomptec-RAIDB/doc/PruebaReadRegistro.xml";
    this->_wpathXMLFile = "/home/darayavilla/Qt_projects/Proyecto2/apcomptec-RAIDB/doc/PruebaWriteRegistro.xml";
    this->_pathBACKUP = "/home/darayavilla/Qt_projects/Proyecto2/apcomptec-RAIDB/doc/PruebaWriteRegistro.xml";
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

void XMLParser::createFile1(unsigned short pAmountDisks,
                            unsigned short pAmountDiskGroups,
                            unsigned short pAmountUsers)
{
    QDomDocument document;
    // crea un nodo root
    QDomElement root = document.createElement( "root" );
    document.appendChild( root );
    QDomElement disks = document.createElement( "disks" );
    root.appendChild( disks );
    for ( unsigned short i = 0; i < pAmountDisks; ++i ){
        QDomElement disk = document.createElement("disk");
        disk.setAttribute( "id", i );
        disk.setAttribute( "host", "192.168.45.63" );
        disk.setAttribute( "size", "poronga" );
        disk.setAttribute( "blockSize", 1.0 );
        disk.setAttribute( "usedBlocks", 1.0 );
        disks.appendChild( disk );
    }
    QDomElement diskGroups = document.createElement( "diskGroups" );
    root.appendChild( diskGroups );
    for ( unsigned short i = 0; i < pAmountDiskGroups; ++i ){
        QDomElement diskGroup = document.createElement("diskGroup");
        diskGroup.setAttribute( "id", pAmountDiskGroups );
        diskGroup.setAttribute( "raid", 0 );
        diskGroup.setAttribute( "size", 1.8 );
        diskGroup.setAttribute( "blockSize", 1.0 );

        QDomElement diskPosee = document.createElement( "disks" );
        diskGroups.appendChild( diskPosee );
        for ( unsigned short i = 0; i < pAmountDiskGroups; ++i ){
            QDomElement disk1 = document.createElement("disk");
            disk1.setAttribute( "id", 0 );
            diskPosee.appendChild( disk1 );
        }
        diskGroups.appendChild( diskGroup );
    }
    QDomElement users = document.createElement( "users" );
    root.appendChild( users );
    for ( unsigned short i = 0; i < pAmountUsers; ++i ){
        QDomElement user = document.createElement("user");
        user.setAttribute( "id", pAmountUsers );
        user.setAttribute( "name", "Joe Pino" );
        user.setAttribute( "pass", 1.0 );
        user.setAttribute( "diskGroup", 3 );
        users.appendChild( user );
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

void XMLParser::createFile(){}


/**
 * @brief XMLParser::~XMLParser
 * Destructor
 */
XMLParser::~XMLParser(){}
