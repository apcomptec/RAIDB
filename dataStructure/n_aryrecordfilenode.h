#ifndef N_ARYRECORDFILENODE_H
#define N_ARYRECORDFILENODE_H
#include <dataStructure/IN_aryNode.h>
#include <fileHandling/IRecord.h>

template<typename DATATYPE>
class N_aryRecordFileNode: public IN_aryNode<DATATYPE>
{
private:
    DATATYPE _data;
    IN_aryNode<DATATYPE>* _parentPtr;
    DLL<IN_aryNode<DATATYPE>*>* _dirListPtr;
    DLL<IN_aryNode<DATATYPE>*>* _fileListPtr;

public:
    N_aryRecordFileNode(DATATYPE pData, IN_aryNode<DATATYPE> pParent = NULL);
    ~N_aryRecordFileNode();

    //SET Y GET PARAMETROS
    DATATYPE getData();
    void setData(DATATYPE);
    IN_aryNode<DATATYPE>* getParentPtr();
    void setParentPtr(IN_aryNode<DATATYPE>*);
    DLL<IN_aryNode<DATATYPE>*>* getChildList();
    void setChildList(DLL<IN_aryNode<DATATYPE> *> *);

    //METODOS IMPLEMENTADOS
    bool addChildPtr(IN_aryNode<DATATYPE> *);
    IN_aryNode<DATATYPE>* deleteChildPtr(IN_aryNode<DATATYPE> *);
    IN_aryNode<DATATYPE>* searchChildPtr(IN_aryNode<DATATYPE> *);

    //METODOS ARBOL N-ARIO DE ARCHIVOS
    DLL<IRecord*>* getRecordFileListPtr();
    void setRecordFileListPtr(DLL<IRecord*>);
    bool addRecordFilePtr(IRecord*);
    IRecord* deleteRecordFilePtr(IRecord*);
    IRecord* searchRecordFilePtr(IRecord*);


};

#endif // N_ARYRECORDFILENODE_H
