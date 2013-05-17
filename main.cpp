#include <fstream>
#include <iostream>
#include "dataStructure/n_aryrecordfile.h"
#include "dataStructure/n_aryrecordfile.cpp"
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "XMLParser.h"

using namespace std;
#define SizeBlock ((5<<20) - 1)

int main(){
//    ofstream ofs("output.raw", ios::out);
//    ofs.write("Hola", 4);
//    cout << SizeBlock << endl;
//    ofs.seekp(SizeBlock);
//    ofs.write("",1);
//    ofs.close();

//    cout << "Leyendo el archivo" << endl;
//    ifstream ifs("output.raw", ios::in);

//    char linea[128];
//    long contador = 0L;

//    if(ifs.fail())
//        cerr << "Error al abrir el ifs output.raw" << endl;
//    else
//        while(ifs.tellg() != SizeBlock)
//        {
//            ifs.getline(linea, sizeof(linea));
//            ifs.seekg(contador, ios::beg);
//            ifs.read(linea, sizeof(linea));
//            cout << linea << endl;
//            contador += sizeof(linea);
//            if((contador % 24)==0)
//            {
//                cout << "CONTINUA...";
//                cin.get();
//            }
//        }
//    ifs.close();
//    return 0;
/*
    std::string name = "jojo", owner = "ko";
    BTRecordFileMetadata *m = new BTRecordFileMetadata(nullptr, name, owner);

    cout << "Inserción de 10 registros sin mostrar el dato que almacena" << endl;
    BTRecordFile *registro = new BTRecordFile(m);
    DLL<IRecordDataType *> *listaUsuario = new DLL<IRecordDataType *>();
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->insertRecord(listaUsuario);
    registro->printArrayRecord();

    delete listaUsuario;

    cout << "Parseo de un XML" << endl;
    XMLParser *parse = new XMLParser();
    parse->readFile();
    parse->writeFile();
    delete parse;
*/

    N_aryRecordFile* nTree = new N_aryRecordFile();
    QString node, root;
    node = "home";
    std::cout << nTree->insertDirPtr(node) << std::endl;
    node = "tmp";
    std::cout << nTree->insertDirPtr(node) << std::endl;
    node = "bin";
    std::cout << nTree->insertDirPtr(node) << std::endl;
    root = "/home/";
    node = "jose";
    std::cout << nTree->insertDirPtr(node, root) << std::endl;
    root = "/home/";
    node = "daniel";
    std::cout << nTree->insertDirPtr(node, root) << std::endl;
    root = "/home/";
    node = "badilla";
    std::cout << nTree->insertDirPtr(node, root) << std::endl;
    root = "/home/jose/";
    node = "dir";
    std::cout << nTree->insertDirPtr(node, root) << std::endl;
    root = "/home/daniel/";
    node = "nueva";
    std::cout << nTree->insertDirPtr(node, root) << std::endl;

    std::cout << "Impresion del arbol" << std::endl;
    nTree->printTree(nTree->getRoot());

    root = "/home/daniel/nueva/";
    std::cout << nTree->deleteDirPtr(root) << std::endl;

    std::cout << "Impresion del arbol" << std::endl;
    nTree->printTree(nTree->getRoot());

    std::cout << "Fin de la ejecución" << std::endl;

    return 0;
}
