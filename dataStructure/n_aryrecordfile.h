#ifndef N_ARYRECORDFILE_H
#define N_ARYRECORDFILE_H
#include "IN_aryTree.h"
#include "dataStructure/n_aryrecordfilenode.h"
#include "dataStructure/n_aryrecordfilenode.cpp"
#include <QStringList>
#include <QRegExp>
#include <QDebug>

class N_aryRecordFile: public IN_aryTree<QString>
{
private:
    IN_aryNode<QString>* _root;
public:
    //Constructor y Destructor
    N_aryRecordFile();
    ~N_aryRecordFile();

    //GETTER Y SETTER
    IN_aryNode<QString>* getRoot();
    void setRoot(IN_aryNode<QString> *);

    //METODOS
    //Insercion de los datos
    bool insertNodePtr(IN_aryNode<QString> *, IN_aryNode<QString>*);
    //Insercion de directorios
    bool insertDirPtr(QString, QString pRoot= "NULL");
    //Insercion de archivos
    bool insertFilePtr(QString pPath, IRecordFile* pFile);
    //Borrado de los datos
    IN_aryNode<QString>* deleteNodePtr(IN_aryNode<QString> *);
    //Borra un directorio
    IN_aryNode<QString>* deleteDirPtr(QString);
    //Borrado de archivos
    IRecordFile* deleteFilePtr(QString);
    //Busqueda de los datos
    IN_aryNode<QString>* searchNodePtr(IN_aryNode<QString> *);
    //Buscador de directorios
    IN_aryNode<QString>* searchDir(QString);
    //Busqueda especial para directorios
    IN_aryNode<QString>* searchDirPtr(IN_aryNode<QString>*, QStringList);
    //Impresion del arbol n-ario
    void printTree();
    void printTreeAux(IN_aryNode<QString>*, QString);
};

#endif // N_ARYRECORDFILE_H
