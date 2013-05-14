#include <fstream>
#include <iostream>
#include "dataStructure/DLL.h"
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
////            ifs.getline(linea, sizeof(linea));
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

    std::string name = "jojo", owner = "ko";
    BTRecordFileMetadata *m = new BTRecordFileMetadata(nullptr, name, owner);

    cout << "Inserción de 10 registros sin mostrar el dato que almacena" << endl;
    BTRecordFile *registro = new BTRecordFile(m);
    BTRecord *record = new BTRecord();
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
    registro->deleteRecord(3);// se borra el registro 3
    registro->printArrayRecord();
    registro->deleteRecord(5);// se borra el registro 5
    registro->printArrayRecord();
    registro->deleteRecord(8);// se borra el registro 8
    registro->printArrayRecord();
    registro->deleteRecord(10);// se borra el registro 10
    registro->printArrayRecord();
    registro->insertRecord(listaUsuario);
    registro->printArrayRecord();
    delete listaUsuario;
    delete registro;
/*
    cout << "Parseo de un XML" << endl;
    XMLParser *parse = new XMLParser();
    //parse->readFile();
    //parse->writeFile();
    delete parse;
*/

}
