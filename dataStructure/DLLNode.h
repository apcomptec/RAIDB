/*******************************************************************************
 * File: DLLNode.h
 * Author: Brallan Aguilar
 * Description: Allows to create a doubly linked list node
 * Reference: C++ How to program (Deitel)
 ******************************************************************************/

#ifndef DLLNODE_H
#define DLLNODE_H

// forward declaration of class DLL required to announce that class DLL exists
// so it can be used in the friend declaration at line 20
template<typename NODETYPE> class DLL;

template<typename NODETYPE>
class DLLNode
{
    friend class DLL<NODETYPE>; // make List a friend

public:

    /**
     * @brief DLLNode Constructor
     * @param pData Node data
     */
    DLLNode(const NODETYPE &pData);

    /**
     * @brief getData
     * @return Node data
     */
    NODETYPE getData() const;

    DLLNode<NODETYPE> *getPrevPtr();
    DLLNode<NODETYPE> *getNextPtr();
    void setPrevPtr(DLLNode<NODETYPE> *pPrevPtr);
    void setNextPtr(DLLNode<NODETYPE> *pNextPtr);

private:

    /**
     * @brief _data Node data
     */
    NODETYPE _data;

    /**
     * @brief _prevPtr Pointer to previous node
     * @brief _nextPtr Pointer to next node
     */
    DLLNode<NODETYPE> *_prevPtr, *_nextPtr;
};

// -----------------------------------------------------------------------------
// DLLNODE DEFINITION
// -----------------------------------------------------------------------------

template<typename NODETYPE>
DLLNode<NODETYPE>::DLLNode(const NODETYPE &pData)
    : _data(pData), _prevPtr(nullptr), _nextPtr(nullptr)
{
    // empty body
}

template<typename NODETYPE>
NODETYPE DLLNode<NODETYPE>::getData() const
{
    return _data;
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLLNode<NODETYPE>::getPrevPtr()
{
    return _prevPtr;
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLLNode<NODETYPE>::getNextPtr()
{
    return _nextPtr;
}

template<typename NODETYPE>
void DLLNode<NODETYPE>::setPrevPtr(DLLNode<NODETYPE> *pPrevPtr)
{
    _prevPtr = pPrevPtr;
}

template<typename NODETYPE>
void DLLNode<NODETYPE>::setNextPtr(DLLNode<NODETYPE> *pNextPtr)
{
    _nextPtr = pNextPtr;
}

#endif // DLLNODE_H
