#ifndef N_ARYRECORDFILETREE_H
#define N_ARYRECORDFILETREE_H
#include <n_aryrecordfilenode.h>

template<typename DATATYPE>
class N_aryRecordFileTree
{
private:
    N_aryRecordFileNode<DATATYPE>* _root;

public:
    N_aryRecordFileTree();
    ~N_aryRecordFileNode();

    //METODOS
    IN_aryNode<DATATYPE>* getRoot();
    void setRoot(IN_aryNode<DATATYPE>*);
    void insertNodePtr(IN_aryNode<DATATYPE>*);
    IN_aryNode<DATATYPE>* deleteNodePtr(IN_aryNode<DATATYPE>*);
    IN_aryNode<DATATYPE>* searcheNodePtr(IN_aryNode<DATATYPE>*);
};

#endif // N_ARYRECORDFILETREE_H
