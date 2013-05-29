#include "n_aryrecordfile.h"

/**
 * @brief N_aryRecordFile::N_aryRecordFile
 */
N_aryRecordFile::N_aryRecordFile()
{
    this->_root = new N_aryRecordFileNode<QString>("/");
}

/**
 * @brief N_aryRecordFile::~N_aryRecordFile
 */
N_aryRecordFile::~N_aryRecordFile()
{
}

/**
 * @brief N_aryRecordFile::getRoot
 * @return _root
 */
IN_aryNode<QString>* N_aryRecordFile::getRoot()
{
    //Se obtiene el nodo raiz
    return this->_root;
}

/**
 * @brief N_aryRecordFile::setRoot
 * @param pRoot
 */
void N_aryRecordFile::setRoot(IN_aryNode<QString> * pRoot)
{
    //Se define el nodo raiz
    this->_root = pRoot;
}

/**
 * @brief N_aryRecordFile::insertNodePtr
 * @param pFolder
 * @param pRoot
 * @return
 */
bool N_aryRecordFile::insertNodePtr(IN_aryNode<QString> * pFolder, IN_aryNode<QString> * pRoot)
{
    if(pRoot == nullptr)
    {
        this->_root = pFolder;
        std::cout << "Root inserted..." << std::endl;
        return true;
    }
    pRoot->addChildPtr(pFolder);
    std::cout << "Child inserted..." << std::endl;
    return true;
}

/**
 * @brief N_aryRecordFile::insertDirPtr
 *  Metodo para la insercion de un directorio dentro del arbol n_ario.
 * @param pNewDir
 * @param pRoot
 * @return true, false
 */
bool N_aryRecordFile::insertDirPtr(QString pNewDir, QString pRoot)
{
    //Se crea el nuevo nodo
    N_aryRecordFileNode<QString>* nNode = new N_aryRecordFileNode<QString>(pNewDir);
    //Verificacion si la raiz donde se inserta es nula
    if(pRoot == "NULL")
    {
        this->_root->addChildPtr(nNode);
        return true;
    }//Se busca la posicion donde insertar
    else{
        //Se crea una lista con los nombres de las carpetas del directorio
        QStringList listPath;
        listPath = pRoot.split(QRegExp("/"));
        listPath.removeFirst();

        //Se busca el nodo padre donde se inserta el nuevo nodo
        IN_aryNode<QString>* current = this->searchDirPtr(this->_root, listPath);

        //Se verifica si el directorio es valido
        if(current != nullptr)
        {
            nNode->setParentPtr(current);
            return current->addChildPtr(nNode);
        }else{
            std::cout << "No existe el directorio" << std::endl;
            return false;
        }
    }
}

bool N_aryRecordFile::insertFilePtr(QString pPath, IRecordFile *pFile)
{
    if(pPath == "Root")
    {
        ((N_aryRecordFileNode<QString>*)this->_root)->addRecordFilePtr(pFile);
        return true;
    }else
    {
        //Se obtiene los directorios
        QStringList listPath;
        listPath = pPath.split(QRegExp("/"));
        listPath.removeFirst();

        //Se busca el nodo padre donde se inserta el nuevo nodo
        IN_aryNode<QString>* current = this->searchDirPtr(this->_root, listPath);

        //Se verifica si el directorio es valido
        if(current != nullptr)
        {
            ((N_aryRecordFileNode<QString>*)current)->addRecordFilePtr(pFile);
            return true;
        }else{
            std::cout << "No existe el directorio" << std::endl;
            return false;
        }
    }
}

/**
 * @brief N_aryRecordFile::deleteDirPtr
 * @param pPath
 * @return true false
 */
IN_aryNode<QString>* N_aryRecordFile::deleteDirPtr(QString pPath)
{
    //Se obtiene los nombre de las direcciones
    QStringList listPath;
    listPath = pPath.split(QRegExp("/"));
    listPath.removeFirst();

    //Se busca el nodo padre donde se inserta el nuevo nodo
    IN_aryNode<QString>* tmpNode = this->searchDirPtr(this->_root, listPath);

    if(tmpNode == nullptr)
    {
        return nullptr;
    }
    return this->deleteNodePtr(tmpNode);

}

/**
 * @brief N_aryRecordFile::deleteNodePtr
 * @param pFolder
 * @return childNode
 */
IN_aryNode<QString>* N_aryRecordFile::deleteNodePtr(IN_aryNode<QString> * pFolder)
{
    pFolder->getParentPtr()->deleteChildPtr(pFolder);
    return pFolder;
}

IRecordFile* N_aryRecordFile::deleteFilePtr(QString pPath)
{
}
/**
 * @brief N_aryRecordFile::searchNodePtr
 * @param pFolder
 * @return childNode
 */
IN_aryNode<QString>* N_aryRecordFile::searchNodePtr(IN_aryNode<QString> * pFolder)
{
    return nullptr;
}

/**
 * @brief N_aryRecordFile::searchDir
 *  Metodo para busqueda de un directorio especifico
 * @param pPath
 * @return childNode
 */
IN_aryNode<QString>* N_aryRecordFile::searchDir(QString pPath)
{
    //Se crea una lista con los nombres de las carpetas del directorio
    QStringList listPath;
    listPath = pPath.split(QRegExp("/"));
    listPath.removeFirst();

    //Se busca el nodo padre donde se inserta el nuevo nodo
    IN_aryNode<QString>* tmpNode = this->searchDirPtr(this->_root, listPath);

    return tmpNode;
}


/**
 * @brief N_aryRecordFile::searchDirPtr
 *  Metodo para buscar un directorio donde se obtiene el nodo deseado
 * @param pRoot
 * @param pPath
 * @return _childNode
 */
IN_aryNode<QString>* N_aryRecordFile::searchDirPtr(IN_aryNode<QString> * pRoot, QStringList pPath)
{
    //Lista temporal de los hijos
    DLL<IN_aryNode<QString>*>* tmpList = pRoot->getChildList();

    //Nodo temporal
    DLLNode<IN_aryNode<QString>*>* tmpNode = tmpList->getHeadPtr();

    //Se obtiene la primera direccion
    QString tmpData = pPath.front();
    pPath.removeFirst();

    //Ciclo de busque de la posicion
    while(tmpNode != nullptr && tmpNode->getData()->getData() != tmpData)
    {
        tmpNode = tmpNode->getNextPtr();
    }

    //Verificacion si el directorio no se encuentra
    if(tmpNode == nullptr)
    {
        return nullptr;
    }//Verificacion si ya no existen datos
    else if(pPath.size() == 1)
    {
        return tmpNode->getData();
    }//Llamada recursiva para la busqueda en niveles mas abajo
    else{
        return this->searchDirPtr(tmpNode->getData(), pPath);
    }
}

/**
 * @brief N_aryRecordFile::printTree
 */
void N_aryRecordFile::printTree()
{
    this->printTreeAux(this->_root, "/");
}


/**
 * @brief N_aryRecordFile::printTree
 * Metodo auxiliar para imprimir los datos de la raiz y sus hijos
 * @param pRoot
 */
void N_aryRecordFile::printTreeAux(IN_aryNode<QString>* pRoot, QString pPath)
{
    //Se imprime la raiz
    qDebug() << pPath;
    //Se obtiene la lista de nodos hijos
    DLL<IN_aryNode<QString>*>* list = pRoot->getChildList();
    //Se obtiene el primer nodo de la lista
    DLLNode<IN_aryNode<QString>*>* tmpNode = list->getHeadPtr();
    //Ciclo para imprimir los hijos
    for (int var = 0; var < list->getSize(); ++var) {
        QString Path = pPath + tmpNode->getData()->getData()+ "/";

        //LLamada recursiva para imprimir los datoS
        this->printTreeAux(tmpNode->getData(), Path);

        //Se mueven las referencias
        tmpNode = tmpNode->getNextPtr();
    }
}
