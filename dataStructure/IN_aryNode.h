#ifndef IN_ARYNODE_H
#define IN_ARYNODE_H
#include <dataStructure/DLL.h>

template<typename DATATYPE>
class IN_aryNode
{
public:
    //Constructor
    IN_aryNode();
    //Destructor
    ~IN_aryNode();

    //SET Y GET DE LOS PARAMETROS

    //Obtener el dato almacenado
    virtual DATATYPE getData() = 0;
    //Definir el dato almacenado
    virtual void setData(DATATYPE) = 0;
    //Obtener el nodo padre
    virtual IN_aryNode<DATATYPE> getParentPtr() = 0;
    //Definir el nodo padre
    virtual void setParentPtr(IN_aryNode<DATATYPE>*) = 0;
    //Obtener la lista de hijos
    virtual DLL<IN_aryNode<DATATYPE>*>* getChildList() = 0;
    //Define la lista de hijos
    virtual void setChildList(DLL<IN_aryNode<DATATYPE>*>*) = 0;

    //METODOS

    //Añadir hijo a la lista
    virtual bool addChildPtr(IN_aryNode<DATATYPE>*) = 0;
    //Borrar un hijo de la lista
    virtual IN_aryNode<DATATYPE>* deleteChildPtr(IN_aryNode<DATATYPE>*) = 0;
    //Buscar un hijo en la lista
    virtual IN_aryNode<DATATYPE>* searchChildPtr(IN_aryNode<DATATYPE>*) = 0;

};

#endif // IN_ARYNODE_H
