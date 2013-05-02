#ifndef IN_ARYNODE_H
#define IN_ARYNODE_H
#include "SimpleList.h"
#include "SimpleList.cpp"

template<typename Data>
class IN_aryNode
{
public:
    IN_aryNode();
    ~IN_aryNode();
    virtual Data getData() = 0;
    virtual void setData(Data) = 0;
    virtual SimpleList<IN_aryNode<Data>*>* getChilds() = 0;
    virtual IN_aryNode<Data>* getFather() = 0;
    virtual void setFather(IN_aryNode<Data>*) = 0;
    virtual void addChild() = 0;
};

#endif // IN_ARYNODE_H
