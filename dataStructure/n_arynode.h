#ifndef N_ARYNODE_H
#define N_ARYNODE_H
#include "In_arynode.h"

template<typename Data>
/**
 * @brief The N_aryNode class
 *  Clase que implementa la interfaz IN_aryNode, la cual,
 *  almacena un dato y almacena las referencias de los nodos
 *  hijos en un arbol n-ario.
 */
class N_aryNode: public IN_aryNode<Data>
{
private:
    //Dato almacenado
    Data _data;
    //Nodo padre
    IN_aryNode<Data>* _father;
    //Lista de nodos hijos
    SimpleList<IN_aryNode<Data>*>* _childs;

public:
    //Constructor
    N_aryNode(Data);
    //Destructor
    ~N_aryNode();

    //METODOS

    //Se obtiene el dato almacenado
    Data getData();
    //Se define el dato almacenado
    void setData(Data);
    //Se inserta un hijo a la lista de hijos
    void insertChild(IN_aryNode<Data>*);
    //Se obtiene la lista de hijos
    SimpleList<IN_aryNode<Data>*> getChilds();
    //Se define el padre del nodo
    void setFather(IN_aryNode<Data> *);
    //Se obtiene el nodo padre
    IN_aryNode<Data>* getFather();
};

#endif // N_ARYNODE_H
