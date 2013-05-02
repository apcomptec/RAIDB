#include "n_arynode.h"

template<typename Data>
/**
 * @brief N_aryNode<Data>::N_aryNode
 *  Constructor de la clase se inicializan las variables
 * @param pData
 */
N_aryNode<Data>::N_aryNode(Data pData)
{
    //Se inicializa el dato
    this->_data = pData;
    //Se instancia una lista simple
    this->_childs = new SimpleList<IN_aryNode<Data>*>();
}

template<typename Data>
/**
 * @brief N_aryNode<Data>::~N_aryNode
 *  Destructor de la clase se libera la memoria
 */
N_aryNode<Data>::~N_aryNode(){
    //Se libera la memoria de la lista
    free(this->_childs);
    //Se libera la memoria del nodo padre
    free(this->_father);
}

template<typename Data>
/**
 * @brief N_aryNode<Data>::getData
 *  Se obtiene el dato almacenado en el nodo
 * @return _data
 */
Data N_aryNode<Data>::getData(){
    //Se devuelve el dato
    return this->_data;
}

template<typename Data>
/**
 * @brief N_aryNode<Data>::setData
 *  Se define el dato y se modifica
 * @param pData
 */
void N_aryNode<Data>::setData(Data pData){
    //Se define el dato
    this->_data = pData;
}

template<typename Data>
/**
 * @brief N_aryNode<Data>::getFather
 *  Se obtiene el nodo padre
 * @return _father
 */
IN_aryNode<Data>* N_aryNode<Data>::getFather(){
    //Se devuelve el nodo padre
    return this->_father;
}

template<typename Data>
/**
 * @brief N_aryNode<Data>::setFather
 *  Metodo para definir el nodo padre
 * @param pFather
 */
void N_aryNode<Data>::setFather(IN_aryNode<Data> * pFather){
    //Se cambia la referencia del nodo padre
    this->_father = pFather;
}

template<typename Data>
/**
 * @brief N_aryNode::getChilds
 *  Metodo para obtener la lista de nodos hijos
 * @return _childs
 */
SimpleList<IN_aryNode<Data>*> N_aryNode::getChilds(){
    //Se devuelve los nodos hijos
    return this->_childs;
}

template<typename Data>
/**
 * @brief N_aryNode<Data>::insertChild
 *  Metodo para insertar un nodo hijo dentro de la lista
 * @param pNode
 */
void N_aryNode<Data>::insertChild(IN_aryNode<Data>* pNode){
    //Se inserta en nodo hijo
    this->_childs->insertFinal(pNode);
}
