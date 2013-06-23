#include "XMLParser.h"

//  http://www.youtube.com/watch?v=IrFOM0azfxQ

XMLParser::XMLParser()
{
    this->_pathXMLFile = "doc/PruebaReadRegistro.xml";
    this->_wpathXMLFile = "doc/PruebaWriteRegistro.xml";
    this->_pathBACKUP = "doc/BackUp.xml";
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

void XMLParser::readBackUp()
{
    QStandardItem *root = new QStandardItem( "root" );
    QDomDocument document;
    QFile file( _pathBACKUP );
    if( file.open(QIODevice::ReadOnly | QIODevice::Text) ){
        document.setContent( &file );
        file.close();
    }

    QDomElement xmlRoot = document.firstChildElement();
    QDomElement disksID = xmlRoot.elementsByTagName("disks").at(0).toElement();


    QDomNodeList disks = disksID.elementsByTagName("disk");
    for (int var = 0; var < disks.count(); ++var) {
        QDomElement element = disks.at(var).toElement();
        qDebug() << "Disco #" << element.attribute("id");
        qDebug() << "Numero de Bloques usados:" << element.attribute("usedBlocks");
        qDebug() << "IP: " << element.attribute("host");
        qDebug() << "Tamaño de bloques: " << element.attribute("blockSize");
        qDebug() << "Tamaño de Disco: " << element.attribute("size");
    }

    QDomNodeList diskGroups = xmlRoot.elementsByTagName("diskGroups");
    for (int var = 0; var < diskGroups.count(); ++var) {
        QDomElement diskGroup = diskGroups.at(var).toElement();
        qDebug() << "Raid #" << diskGroup.attribute("raid");
        qDebug() << "Tamaño: " << diskGroup.attribute("size");
        qDebug() << "Tamaño de bloque: " << diskGroup.attribute("blockSize");
        qDebug() << "ID: " << diskGroup.attribute("id");
        QDomElement disks = diskGroup.elementsByTagName("disks").at(0).toElement();
        QDomNodeList disk = disks.elementsByTagName("disk");
        for (int var = 0; var < disk.count(); ++var) {
            QDomElement diskElem = disk.at(0).toElement();
            qDebug() << "ID: " << diskElem.attribute("id");
        }
    }

    QDomElement users = xmlRoot.elementsByTagName("users").at(0).toElement();
    QDomNodeList userList = users.elementsByTagName("user");
    for (int var = 0; var < userList.count(); ++var) {
        QDomElement user = userList.at(var).toElement();
        qDebug() << "Nombre: " << user.attribute("name");
        qDebug() << "Password: " << user.attribute("pass");
        qDebug() << "ID: " << user.attribute("id");
        qDebug() << "Grupo de Disco #" << user.attribute("diskGroup");
    }
    qDebug() << "Arbol N-ario";

    QDomElement rootFolder = xmlRoot.elementsByTagName("folder").at(0).toElement();
    this->readN_ary(rootFolder, "");
}

void XMLParser::readN_ary(QDomElement element, QString pPath)
{
    qDebug() << pPath << element.attribute("name") << "/";
    QDomNodeList paths = element.elementsByTagName("folder");
    for (int var = 0; var < paths.count(); ++var) {
        QDomElement folder = paths.at(var).toElement();
        this->readN_ary(folder, pPath+element.attribute("name")+"/");
    }
}

/**
 * @brief XMLParser::writeFile
 * Escribe un XML
 */
void XMLParser::writeFile(){
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

void XMLParser::writeN_aryXML(IN_aryNode<QString>* pRoot, QDomElement pRootXML, QDomDocument pDocument)
{
    DLLNode<IN_aryNode<QString>*>* folder = pRoot->getChildList()->getHeadPtr();
    while( folder != nullptr )
    {
        QDomElement xmlChild = pDocument.createElement("folder");
        xmlChild.setAttribute("name", folder->getData()->getData());
        pRootXML.appendChild(xmlChild);
        this->writeN_aryXML(folder->getData(), xmlChild, pDocument);
        folder = folder->getNextPtr();
    }
    DLLNode<IRecordFile*>* file = (dynamic_cast<N_aryRecordFileNode<QString>*>(pRoot))->getRecordFileListPtr()->getHeadPtr();
    while(file != nullptr)
    {
        QDomElement xmlChild = pDocument.createElement("file");
        xmlChild.setAttribute("name", Converter::fromStringToQString(
                                  file->getData()->getMetadata()->getFileName()));
        xmlChild.setAttribute("owner", Converter::fromStringToQString(
                                  file->getData()->getMetadata()->getOwner()));
        pRootXML.appendChild(xmlChild);
        file = file->getNextPtr();
    }
}

/**
 * Función para crear el Back Up
 * @brief XMLParser::generateBackUp
 * @param pAmountDisks
 * @param pAmountDiskGroups
 * @param pAmountUsers
 */
void XMLParser::generateBackUp(unsigned short pAmountDisks,
                               unsigned short pAmountDiskGroups,
                               unsigned short pAmountUsers, IN_aryNode<QString> *pRoot)
{
    QDomDocument document;      // Se crea el documento xml
    QDomElement root = document.createElement( "root" );    // crea un root
    document.appendChild( root );   // se añade el root al documento
    QDomElement disks = document.createElement( "disks" );  // discos
    root.appendChild( disks );
    for ( unsigned short i = 0; i < pAmountDisks; ++i ){    // Atributos de discos
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
    for ( unsigned short i = 0; i < pAmountDiskGroups; ++i ){// Atributos de diskGroups
        QDomElement diskGroup = document.createElement("diskGroup");
        diskGroup.setAttribute( "id", pAmountDiskGroups );
        diskGroup.setAttribute( "raid", 0 );
        diskGroup.setAttribute( "size", 1.8 );
        diskGroup.setAttribute( "blockSize", 1.0 );

        QDomElement diskPosee = document.createElement( "disks" );
        diskGroup.appendChild( diskPosee );
        for ( unsigned short i = 0; i < pAmountDiskGroups; ++i ){
            QDomElement disk1 = document.createElement("disk");
            disk1.setAttribute( "id", 0 );
            diskPosee.appendChild( disk1 );
        }
        diskGroups.appendChild( diskGroup );
    }
    QDomElement users = document.createElement( "users" );
    root.appendChild( users );
    for ( unsigned short i = 0; i < pAmountUsers; ++i ){    // Atributos de users
        QDomElement user = document.createElement("user");
        user.setAttribute( "id", pAmountUsers );
        user.setAttribute( "name", "Joe Pino" );
        user.setAttribute( "pass", 1.0 );
        user.setAttribute( "diskGroup", 3 );
        users.appendChild( user );
    }
    // crea un nodo root
    QDomElement rootN_ary = document.createElement("folder");
    rootN_ary.setAttribute("name", "root");
    root.appendChild(rootN_ary);
    this->writeN_aryXML(pRoot, rootN_ary, document);
    // guardar archivo
    QFile file( _pathBACKUP );    // Se almacena el xml en un doc
    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) ){
        qDebug() << "Error al guardar archivo";
    }
    QTextStream stream( &file );
    stream << document.toString();
    file.close();
    qDebug() << "Archivo Guardado";
}


/**
 * @brief XMLParser::~XMLParser
 * Destructor
 */
XMLParser::~XMLParser(){}
