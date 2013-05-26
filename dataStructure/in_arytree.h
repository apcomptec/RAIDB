#ifndef IN_ARYTREE_H
#define IN_ARYTREE_H
#include <IN_aryNode.h>

template<typename DATATYPE>
class IN_aryTree
{
public:
    IN_aryTree();
    ~IN_aryNode();

    //METODOS

    virtual IN_aryNode<DATATYPE>* getRoot() = 0;
    virtual void setRoot(IN_aryNode<DATATYPE>*) = 0;
    virtual void insertNodePtr(IN_aryNode<DATATYPE>*) = 0;
    virtual IN_aryNode<DATATYPE>* deleteNodePtr(IN_aryNode<DATATYPE>*) = 0;
    virtual IN_aryNode<DATATYPE>* searcheNodePtr(IN_aryNode<DATATYPE>*) = 0;
};

#endif // IN_ARYTREE_H
