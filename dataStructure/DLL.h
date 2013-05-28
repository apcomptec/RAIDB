/*******************************************************************************
 * File: DLL.h
 * Author: Brallan Aguilar
 * Description: Generic doubly linked list
 * Reference: C++ How to program (Deitel)
 ******************************************************************************/

#ifndef DLL_H
#define DLL_H

#include <iostream>
#include "dataStructure/DLLNode.h"

template<typename NODETYPE>
class DLL
{
public:

    /**
     * @brief DLL Constructor
     */
    DLL();

    /**
     * @brief ~DLL Destructor
     */
    ~DLL();

    /**
     * @brief insertAtFront
     * @param pData Data to be inserted
     */
    void insertAtFront(const NODETYPE &pData);

    /**
     * @brief insertAtBack
     * @param pData Data to be inserted
     */
    void insertAtBack(const NODETYPE &pData);

    /**
     * @brief insertInOrderND insert in order without duplicates
     * @param pData Data to be inserted
     */
    void insertInOrderND(const NODETYPE &pData);

    /**
     * @brief insertInOrderD insert in order with duplicates
     * @param pData Data to be inserted
     */
    void insertInOrderD(const NODETYPE &pData);

    /**
     * @brief removeFromFront
     * @return pointer to removed element. If it didn't, returns nullptr
     */
    DLLNode<NODETYPE> *removeFromFront();

    /**
     * @brief removeFronBack
     * @return pointer to removed element. If it didn't, returns nullptr
     */
    DLLNode<NODETYPE> *removeFromBack();

    /**
     * @brief removeSpecific
     * @return pointer to removed element. If it didn't, returns nullptr
     */
    DLLNode<NODETYPE> *removeSpecific(const NODETYPE &pData);

    /**
     * @brief searchInOrder
     * @param pData Data to find out
     * @return Data (if was found) or nullptr (if was not found)
     */
    DLLNode<NODETYPE> *searchInOrder(const NODETYPE &pData);

    /**
     * @brief searchNotInOrder Search in disorder list
     * @param pData Data to find out
     * @return Data (if was found) or nullptr (if was not found)
     */
    DLLNode<NODETYPE> *searchNotInOrder(const NODETYPE &pData);

    /**
     * @brief isEmpty
     * @return is DLL empty?
     */
    bool isEmpty() const;

    /**
     * @brief getSize
     * @return List size. Allows 65535 items maximum
     */
    unsigned short getSize() const;

    DLLNode<NODETYPE> *getHeadPtr() const;
    DLLNode<NODETYPE> *getTailPtr() const;

private:

    /**
     * @brief _headPtr Pointer to head
     * @brief _tailPtr Pointer to tail
     */
    DLLNode<NODETYPE> *_headPtr, *_tailPtr;

    /**
     * @brief _size List size. Allows 65535 items maximum
     */
    unsigned short _size;

    /**
     * @brief getNewNode utility function to allocate new node
     * @return New pointer to DLLNode
     */
    DLLNode<NODETYPE> *getNewNode(const NODETYPE &pData);
};

// -----------------------------------------------------------------------------
// DLL IMPLEMENTATION
// -----------------------------------------------------------------------------

template<typename NODETYPE>
DLL<NODETYPE>::DLL()
    : _headPtr(nullptr), _tailPtr(nullptr), _size(0)
{
    // empty body
}

template<typename NODETYPE>
DLL<NODETYPE>::~DLL()
{
    if (!isEmpty()) {
        std::cout << "Destroying nodes...\n";

        DLLNode<NODETYPE> *currentPtr = _headPtr;
        DLLNode<NODETYPE> *tempPtr;

        while (currentPtr != nullptr) {
            tempPtr = currentPtr;
            currentPtr = currentPtr->_nextPtr;
            delete tempPtr;
        }
    }

    std::cout << "All nodes destroyed!\n";
    std::cout << "~DLL\n\n";
}

template<typename NODETYPE>
void DLL<NODETYPE>::insertAtFront(const NODETYPE &pData)
{
    DLLNode<NODETYPE> *newNodePtr = getNewNode(pData); // new node to insert

    if (isEmpty()) {
        _headPtr = _tailPtr = newNodePtr;
    } else {
        newNodePtr->_nextPtr = _headPtr;
        _headPtr->_prevPtr = newNodePtr;
        _headPtr = newNodePtr;
    }

    _size++;
}

template<typename NODETYPE>
void DLL<NODETYPE>::insertAtBack(const NODETYPE &pData)
{
    DLLNode<NODETYPE> *newNodePtr = getNewNode(pData); // new node to insert

    if (isEmpty()) {
        _headPtr = _tailPtr = newNodePtr;
    } else {
        _tailPtr->_nextPtr = newNodePtr;
        newNodePtr->_prevPtr = _tailPtr;
        _tailPtr = newNodePtr;
    }

    _size++;
}

template<typename NODETYPE>
void DLL<NODETYPE>::insertInOrderND(const NODETYPE &pData)
{
    if (isEmpty()) {
        insertAtFront(pData);
    } else if (pData < _headPtr->getData()) {
        insertAtFront(pData);
    } else if (pData > _tailPtr->getData()) {
        insertAtBack(pData);
    } else {
        DLLNode<NODETYPE> *tempPtr = _headPtr;
        while (tempPtr.getData() < pData) {
            tempPtr = tempPtr->_nextPtr;
        }

        DLLNode<NODETYPE> *insertNode = getNewNode(pData);

        if (tempPtr->getData() > pData) {
            insertNode->_prevPtr = tempPtr->_prevPtr;
            insertNode->_nextPtr = tempPtr;

            tempPtr->_prevPtr->_nextPtr = insertNode;
            tempPtr->_prevPtr = tempPtr;
        } else {
            std::cout << "El dato " << pData << " ya existe\n\n";
        }
    }
}

template<typename NODETYPE>
void DLL<NODETYPE>::insertInOrderD(const NODETYPE &pData)
{
    if (isEmpty()) {
        insertAtFront(pData);
    } else if (pData <= _headPtr->getData()) {
        insertAtFront(pData);
    } else if (pData >= _tailPtr->getData()) {
        insertAtBack(pData);
    } else {
        DLLNode<NODETYPE> *tempPtr = _headPtr;
        while (tempPtr->getData() < pData) {
            tempPtr = tempPtr->_nextPtr;
        }

        DLLNode<NODETYPE> *insertNode = getNewNode(pData);
        insertNode->_prevPtr = tempPtr->_prevPtr;
        insertNode->_nextPtr = tempPtr;

        tempPtr->_prevPtr->_nextPtr = insertNode;
        tempPtr->_prevPtr = tempPtr;

        _size++;
    }
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLL<NODETYPE>::removeFromFront()
{
    DLLNode<NODETYPE> *deletedNode; // hold deleted node

    if (isEmpty()) {
        deletedNode = nullptr;
    } else {
        deletedNode = _headPtr;

        if (_headPtr == _tailPtr) {
            _headPtr = _tailPtr = nullptr;
        } else {
            _headPtr = _headPtr->_nextPtr;
            _headPtr->_prevPtr = nullptr;
        }
    }

    _size--;

    return deletedNode;
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLL<NODETYPE>::removeFromBack()
{
    DLLNode<NODETYPE> *deletedNode; // hold deleted node

    if (isEmpty()) {
        deletedNode = nullptr;
    } else {
        deletedNode = _tailPtr;

        if (_headPtr == _tailPtr) {
            _headPtr = _tailPtr = nullptr;
        } else {
            _tailPtr = _tailPtr->_prevPtr;
            _tailPtr->_nextPtr = nullptr;
        }
    }

    _size--;

    return deletedNode;
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLL<NODETYPE>::removeSpecific(const NODETYPE &pData)
{
    DLLNode<NODETYPE> *deletedNode;

    if ( this->isEmpty() )
    {
        deletedNode = nullptr;
        return deletedNode;
    }
    else if(this->_headPtr->getData() == pData){
        deletedNode = this->_headPtr;
        if(this->_headPtr == this->_tailPtr){
            _headPtr = _tailPtr = nullptr;
        }else{
            _headPtr->getNextPtr()->setPrevPtr(nullptr);
            _headPtr = _headPtr->getNextPtr();
        }
    }
    else if(_tailPtr->getData() == pData){
        deletedNode = this->_tailPtr;
        _tailPtr = _tailPtr->getPrevPtr();
        _tailPtr->setNextPtr(nullptr);
    }
    else{
        DLLNode<NODETYPE>* tmp = _headPtr;
        while(tmp->getNextPtr() != nullptr && tmp->getNextPtr()->getData() != pData){
            tmp = tmp->getNextPtr();
        }if(tmp != _tailPtr){
            deletedNode = tmp;
            tmp->getNextPtr()->getNextPtr()->setPrevPtr(tmp);
            tmp->setNextPtr(tmp->getNextPtr()->getNextPtr());
        }
        deletedNode = nullptr;
    }

    this->_size--;

    return deletedNode;
}


template<typename NODETYPE>
DLLNode<NODETYPE> *DLL<NODETYPE>::searchInOrder(const NODETYPE &pData)
{
    DLLNode<NODETYPE> *result;
    if (isEmpty() || pData < _headPtr->getData() || pData > _tailPtr->getData()) {
        result = nullptr;
    } else {
        result = _headPtr;
        while (result != nullptr && result->getData() != pData) {
            result = result->_nextPtr;
        }
    }

    return result;
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLL<NODETYPE>::searchNotInOrder(const NODETYPE &pData)
{
    DLLNode<NODETYPE> *current = _headPtr;

    while (current != nullptr && current->getData() != pData) {
        current = current->_nextPtr;
    }

    if (current == nullptr) {
        std::cout << "¡Valor no encontrado!\n\n";
        return nullptr;
    }

    return current;
}

template<typename NODETYPE>
bool DLL<NODETYPE>::isEmpty() const
{
    return _headPtr == nullptr;
}

template<typename NODETYPE>
unsigned short DLL<NODETYPE>::getSize() const
{
    return _size;
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLL<NODETYPE>::getHeadPtr() const
{
    return _headPtr;
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLL<NODETYPE>::getTailPtr() const
{
    return _tailPtr;
}

template<typename NODETYPE>
DLLNode<NODETYPE> *DLL<NODETYPE>::getNewNode(const NODETYPE & pData)
{
    return new DLLNode<NODETYPE>(pData);
}

#endif // DLL_H
