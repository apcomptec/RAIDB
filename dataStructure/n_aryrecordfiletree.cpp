#include "n_aryrecordfiletree.h"

template<typename DATATYPE>
N_aryRecordFileTree<DATATYPE>::N_aryRecordFileTree()
{
    this->_root = 0;
}

template<typename DATATYPE>
N_aryRecordFileTree<DATATYPE>::~N_aryRecordFileTree(){
}

template<typename DATATYPE>
IN_aryNode<DATATYPE>* N_aryRecordFileTree<DATATYPE>::getRoot(){
    return this->_root;
}

template<typename DATATYPE>
void N_aryRecordFileTree<DATATYPE>::setRoot(IN_aryNode<DATATYPE> * pNode){
    this->_root = pNode;
}

template<typename DATATYPE>
void N_aryRecordFileTree<DATATYPE>::insertNodePtr(IN_aryNode<DATATYPE> * pNode){
    if(this->_root == 0){
        this->_root = pNode;
    }else{
        IN_aryNode<DATATYPE>* currentNode = this->_root;
        while(currentNode != pNode->getParentPtr()){
            currentNode->getChildList()->searchNotInOrder(pNode);
        }
        currentNode->addChildPtr(pNode);
    }
}

template<typename DATATYPE>
N_aryRecordFileTree<DATATYPE>::


template<typename DATATYPE>
N_aryRecordFileTree<DATATYPE>::
