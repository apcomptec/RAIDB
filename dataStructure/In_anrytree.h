#ifndef IN_ANRYTREE_H
#define IN_ANRYTREE_H
#include "In_arynode.h"

template<typename Data>
class IN_anryTree
{
public:
    IN_anryTree();
    ~IN_anryTree();
    virtual void insert(Data pData, IN_aryNode<Data>* pFather = 0) = 0;
    virtual Data deleteData(Data) = 0;
    virtual bool searchData(Data) = 0;
};

#endif // IN_ANRYTREE_H
