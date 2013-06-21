#include "n_aryrecordfilenode.h"

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::N_aryRecordFileNode
 *  Constructor del Nodo N-ario
 * @param pData
 * @param pParent
 */
N_aryRecordFileNode<DATATYPE>::N_aryRecordFileNode(DATATYPE pData, IN_aryNode<DATATYPE> *pParent)
{
    //Instancia del dato
    this->_data = pData;
    //Instancia del padre
    this->_parentPtr = pParent;
    //Instancia de la lista de directorios
    this->_dirListPtr = new DLL<IN_aryNode<DATATYPE>*>();
    //Instancia de la lista de archivos
    this->_fileListPtr = new DLL<IRecordFile*>();
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::~N_aryRecordFileNode
 *  Destructor de la clase
 */
N_aryRecordFileNode<DATATYPE>::~N_aryRecordFileNode()
{
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::getData
 *  Metodo para obtener el dato almacenado
 * @return _data
 */
DATATYPE N_aryRecordFileNode<DATATYPE>::getData()
{
    //Se devuelve el dato
    return this->_data;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::setData
 *  Metodo para modificar el dato almacenado
 * @param pData
 */
void N_aryRecordFileNode<DATATYPE>::setData(DATATYPE pData)
{
    //Se define el dato
    this->_data = pData;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::getParentPtr
 *  Metodo para obtener el nodo padre
 * @return _parentPtr
 */
IN_aryNode<DATATYPE>* N_aryRecordFileNode<DATATYPE>::getParentPtr()
{
    //Se obtiene el nodo
    return this->_parentPtr;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::setParentPtr
 *  Metodo para modificar la referencia al nodo padre
 * @param pParent
 */
void N_aryRecordFileNode<DATATYPE>::setParentPtr(IN_aryNode<DATATYPE> * pParent)
{
    //Se modifica la referencia
    this->_parentPtr = pParent;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::getChildList
 *  Metodo que devuelve una lista con los directorios
 * @return _dirListPtr
 */
DLL<IN_aryNode<DATATYPE>*>* N_aryRecordFileNode<DATATYPE>::getChildList()
{
    //Se obtiene la lista
    return this->_dirListPtr;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::setChildList
 *  Metodo para modificar la lista de directorios
 * @param pChilds
 */
void N_aryRecordFileNode<DATATYPE>::setChildList(DLL<IN_aryNode<DATATYPE> *> * pChilds)
{
    //Se define la lista
    this->_dirListPtr = pChilds;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::getRecordFileListPtr
 *  Metodo para obtener la lista de archivos
 * @return _fileList
 */
DLL<IRecordFile*>* N_aryRecordFileNode<DATATYPE>::getRecordFileListPtr()
{
    //Se retorna la lista
    return this->_fileListPtr;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::addChildPtr
 *  Metodo para añadir un nodo hijo al nodo actual
 * @param pChild
 * @return true or false
 */
bool N_aryRecordFileNode<DATATYPE>::addChildPtr(IN_aryNode<DATATYPE> * pChild)
{
    //Se inserta el nodo hijo
    this->_dirListPtr->insertAtBack(pChild);
    //Se devuelve valor booleano
    return true;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::searchChildPtr
 *  Metodo para buscar un nodo hijo dentro de la lista
 * @param pNode
 * @return IN_aryNode
 */
IN_aryNode<DATATYPE>* N_aryRecordFileNode<DATATYPE>::searchChildPtr(IN_aryNode<DATATYPE> * pNode)
{
    //Se devuelve el nodo hijo alamcenado y buscado
    return this->_dirListPtr->searchNotInOrder(pNode)->getData();
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::deleteChildPtr
 *  Metodo que borra un nodo de la lista de hijos
 * @param pNode
 * @return IN_aryNode
 */
IN_aryNode<DATATYPE>* N_aryRecordFileNode<DATATYPE>::deleteChildPtr(IN_aryNode<DATATYPE> * pNode)
{
    //Se borra el nodo buscado
    return this->_dirListPtr->removeSpecific(pNode)->getData();
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::addRecordFilePtr
 *  Metodo para insertar el puntero al archivo
 * @param pFile
 * @return true or false;
 */
bool N_aryRecordFileNode<DATATYPE>::addRecordFilePtr(IRecordFile *pFile)
{
    //Se inserta el puntero al archivo
    this->_fileListPtr->insertAtBack(pFile);
    return true;
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::searchRecordFilePtr
 *  Metodo para buscar el dato especifico
 * @param pFile
 * @return _data
 */
IRecordFile* N_aryRecordFileNode<DATATYPE>::searchRecordFilePtr(std::string pName)
{
    //Se busca y se devuelve el dato
//    return this->_fileListPtr->searchNotInOrder(pFile)->getData();
    DLLNode<IRecordFile*> *current = _fileListPtr->getHeadPtr();
    std::string name = current->getData()->getMetadata()->getFileName();

    while (current != nullptr && name != pName) {
        current = current->getNextPtr();
//        std::cout << "NAME:::: " << (&name == 0); // TEST
    }

    return current->getData();

}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::deleteRecordFilePtr
 *  Metodo para eliminar un puntero al archivo
 * @param pFile
 * @return _data
 */
IRecordFile* N_aryRecordFileNode<DATATYPE>::deleteRecordFilePtr(IRecordFile *pFile)
{
    return this->_fileListPtr->removeSpecific(pFile);
}

template<typename DATATYPE>
/**
 * @brief N_aryRecordFileNode<DATATYPE>::searchDirInto
 *  En este metodo se busca un nodo si se encuentra lo devuelve
 * @param pDir
 * @return Nodo al cual se esta buscando
 */
IN_aryNode<DATATYPE>* N_aryRecordFileNode<DATATYPE>::searchDirInto(IN_aryNode<DATATYPE> * pDir)
{
    //Se obtiene el nodo header
    DLLNode<IN_aryNode<DATATYPE>*>* tmpDir = this->_dirListPtr->getHeadPtr();
    //Comienza un ciclo de busqueda
    for (int var = 0; var < this->_dirListPtr->getSize(); ++var) {
        if (pDir->getData() == tmpDir->getData()->getData()) {
            //En caso de encontrar el nodo lo devuelve
            return tmpDir->getData();
        }
        //Se mueven las referencias de los nodos
        tmpDir = tmpDir->getNextPtr();
    }
    return nullptr;
}
