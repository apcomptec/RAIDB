#include "n_aryrecordfilenode.h"

template<typename DATATYPE>
N_aryRecordFileNode<DATATYPE>::N_aryRecordFileNode(DATATYPE pData, IN_aryNode<DATATYPE> pParent)
{
    this->_data = pData;
    this->_parentPtr = pParent;
    this->_dirListPtr = new DLL<IN_aryNode<DATATYPE>*>();
    this->_fileListPtr = new DLL<IN_aryNode<DATATYPE>*>();
}

template<typename DATATYPE>
N_aryRecordFileNode<DATATYPE>::~N_aryRecordFileNode()
{
}

template<typename DATATYPE>
DATATYPE N_aryRecordFileNode<DATATYPE>::getData()
{
    return this->_data;
}

template<typename DATATYPE>
void N_aryRecordFileNode<DATATYPE>::setData(DATATYPE pData)
{
    this->_data = pData;
}

template<typename DATATYPE>
IN_aryNode<DATATYPE>* N_aryRecordFileNode<DATATYPE>::getParentPtr()
{
    return this->_parentPtr;
}

template<typename DATATYPE>
void N_aryRecordFileNode<DATATYPE>::setParentPtr(IN_aryNode<DATATYPE> * pParent)
{
    this->_parentPtr = pParent;
}

template<typename DATATYPE>
DLL<IN_aryNode<DATATYPE>*>* N_aryRecordFileNode<DATATYPE>::getChildList()
{
    return this->_dirListPtr;
}

template<typename DATATYPE>
void N_aryRecordFileNode<DATATYPE>::setChildList(DLL<IN_aryNode<DATATYPE> *> * pChilds)
{
    this->_dirListPtr = pChilds;
}

template<typename DATATYPE>
bool N_aryRecordFileNode<DATATYPE>::addChildPtr(IN_aryNode<DATATYPE> * pChild)
{
    this->_dirListPtr->insertAtBack(pChild);
}

