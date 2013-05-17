#include <fstream>
#include <iostream>
#include "dataStructure/n_aryrecordfile.h"
#include "dataStructure/n_aryrecordfile.cpp"
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "XMLParser.h"
#include "util/Converter.h"

#include "raid/Disk.h"

using namespace std;

//#define SizeBlock ((5<<20) - 1)

int main()
{
    Converter *c = new Converter();
    c->string2Binary("Hello World!");
}

////    ofstream ofs("output.raw", ios::out);
////    ofs.write("Hola", 4);
////    cout << SizeBlock << endl;
////    ofs.seekp(SizeBlock);
////    ofs.write("",1);
////    ofs.close();

////    cout << "Leyendo el archivo" << endl;
////    ifstream ifs("output.raw", ios::in);

////    char linea[128];
////    long contador = 0L;

////    if(ifs.fail())
////        cerr << "Error al abrir el ifs output.raw" << endl;
////    else
////        while(ifs.tellg() != SizeBlock)
////        {
//////            ifs.getline(linea, sizeof(linea));
////            ifs.seekg(contador, ios::beg);
////            ifs.read(linea, sizeof(linea));
////            cout << linea << endl;
////            contador += sizeof(linea);
////            if((contador % 24)==0)
////            {
////                cout << "CONTINUA...";
////                cin.get();
////            }
////        }
////    ifs.close();

//    //    std::ofstream outfile;
////    outfile.open("test.txt");

////    outfile.write("This is an apple", 16);
////    long pos = outfile.tellp();
////    std::cout << "pos " << pos;
////    outfile.seekp(1927579);
////    const char* text = "fueeeeeeeee";
////    outfile.write(text, sizeof(text));

////    outfile.close();
////    return 0;

////    std::string name = "jojo", owner = "ko";
////    DLL<std::string> dll;
////    dll.insertAtBack("char");
////    dll.insertAtBack("integer");
////    BTRecordFileMetadata *m = new BTRecordFileMetadata(nullptr, name, owner);
////    BTRecordFile *registro = new BTRecordFile(m);
////    DLL<IRecordDataType *> *listaUsuario = new DLL<IRecordDataType *>();

////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->insertRecord(listaUsuario);
////    registro->printArrayRecord();
////    return 0;
//    /*
//        std::string name = "jojo", owner = "ko";
//        BTRecordFileMetadata *m = new BTRecordFileMetadata(nullptr, name, owner);

//        cout << "Inserción de 10 registros sin mostrar el dato que almacena" << endl;
//        BTRecordFile *registro = new BTRecordFile(m);
//        DLL<IRecordDataType *> *listaUsuario = new DLL<IRecordDataType *>();
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->printArrayRecord();

//        delete listaUsuario; */

////    cout << "Parseo de un XML" << endl;
////    XMLParser *parse = new XMLParser();
////    parse->readFile();
////    //parse->writeFile();
////    delete parse;

    // Open a new file for input/output operations discarding any current
    // content in the file (assumes a length of zero on opening)
//    fstream myFile("test.txt", ios::in | ios::out | ios::trunc);

//    // Add the characters "Hello World" to the file
//    myFile << "Hello World";

//    // Seek to 6 characters from the beginning of the file
//    myFile.seekg(6, ios::beg);

//    // Read the next 5 characters from the file into a buffer
//    char buffer[6];
//    myFile.read(buffer, 5);

//    // End the buffer with a null terminating character
//    buffer[5] = 0;

//    // Output the contents read from the file and close it
//    cout << buffer << endl;

//    myFile.close();

//    unsigned short size = 9;
//    Disk disk(4, 1, size);
//    disk.write(4, "turd");
//    disk.write(9, "42398jf8j0jm");
//    disk.write(20, "nvx,3458jd9865a");


//    disk.write(98, "3333");
//    disk.write(40, "jfihf98u498223");
//    disk.write(80, "4324jfihf98u498223");
//    disk.write(120, "dfdai7!+·q#¬½~@½½¬");
//    disk.write(0, "FD$·DDMM;:&$·%·458437rjjfrjoo2985urjefjwrefFFR%%");
//    disk.read(2, 10);
//    disk.read(1, 2);
//    disk.write(98, "3333");
//    disk.write(40, "jfihf98u498223");
//    disk.write(80, "4324jfihf98u498223");
//    disk.write(120, "dfdai7!+·q#¬½~@½½¬");
////    disk.write(0, "FD$·DDMM;:&$·%·458437rjjfrjoo2985urjefjwrefFFR%%");
//    disk.read(2, 10);
//    disk.read(1, 2);

////    ifstream in("test.txt");

////    if (!in) {
////        cout << "Cannot open input file.\n";
////        return 1;
////    }

////    char str[255];

//////    while (in) {
////        in.getline(str, 255);  // delim defaults to '\n'
////           if (in) cout << str << endl;
//////    }

//#define SizeBlock ((5<<20) - 1)

//int main(){
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

//    std::string name = "jojo", owner = "ko";
//    BTRecordFileMetadata *m = new BTRecordFileMetadata(nullptr, name, owner);

//    cout << "Inserción de 10 registros sin mostrar el dato que almacena" << endl;
//    BTRecordFile *registro = new BTRecordFile(m);
//    BTRecord *record = new BTRecord();
//    DLL<IRecordDataType *> *listaUsuario = new DLL<IRecordDataType *>();
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->insertRecord(listaUsuario);
//    registro->printArrayRecord();
//    registro->deleteRecord(3);// se borra el registro 3
//    registro->printArrayRecord();
//    registro->deleteRecord(5);// se borra el registro 5
//    registro->printArrayRecord();
//    registro->deleteRecord(8);// se borra el registro 8
//    registro->printArrayRecord();
//    registro->deleteRecord(10);// se borra el registro 10
//    registro->printArrayRecord();
//    registro->insertRecord(listaUsuario);
//    registro->printArrayRecord();
//    delete listaUsuario;
//    delete registro;
/*
    cout << "Parseo de un XML" << endl;
    XMLParser *parse = new XMLParser();
    parse->readFile();
    parse->writeFile();
    delete parse;
*/
//    N_aryRecordFile* nTree = new N_aryRecordFile();
//    QString node, root;
//    node = "home";
//    std::cout << nTree->insertDirPtr(node) << std::endl;
//    node = "tmp";
//    std::cout << nTree->insertDirPtr(node) << std::endl;
//    node = "bin";
//    std::cout << nTree->insertDirPtr(node) << std::endl;
//    root = "/home/";
//    node = "jose";
//    std::cout << nTree->insertDirPtr(node, root) << std::endl;
//    root = "/home/";
//    node = "daniel";
//    std::cout << nTree->insertDirPtr(node, root) << std::endl;
//    root = "/home/";
//    node = "badilla";
//    std::cout << nTree->insertDirPtr(node, root) << std::endl;
//    root = "/home/jose/";
//    node = "dir";
//    std::cout << nTree->insertDirPtr(node, root) << std::endl;
//    root = "/home/daniel/";
//    node = "nueva";
//    std::cout << nTree->insertDirPtr(node, root) << std::endl;

//    std::cout << "Impresion del arbol" << std::endl;
//    nTree->printTree(nTree->getRoot());

//    root = "/home/daniel/nueva/";
//    std::cout << nTree->deleteDirPtr(root) << std::endl;

//    std::cout << "Impresion del arbol" << std::endl;
//    nTree->printTree(nTree->getRoot());

//    std::cout << "Fin de la ejecución" << std::endl;

//    return 0;
////    in.close();
////    std::ifstream file("test.txt");

////    // print contents the first time
////    std::cout << file.rdbuf();

////    // seek to the beginning
////    file.seekg(0);

////    // print contents the second time
////    std::cout << file.rdbuf();
///

//    std::ifstream is("test.txt", std::ifstream::binary);
//    if (is) {
//        // get length of file:
//        is.seekg(0, is.end);
//        int length = is.tellg();
//        is.seekg(0, is.beg);

//        // allocate memory:
//        char * buffer = new char [length];

//        // read data as a block:
//        is.read(buffer, length);

//        is.close();

//        // print content:
//        std::cout.write(buffer, length);

//        delete[] buffer;
//    }
    // Open a new file for input/output operations discarding any current
    // content in the file (assumes a length of zero on opening)
//    fstream myFile("test.txt", ios::in | ios::out | ios::trunc);

//    // Add the characters "Hello World!" to the file
//    myFile << "Hello World!";

//    // Seek to 6 characters from the beginning of the file
//    myFile.seekg(6, ios::beg);

//    // Read the next 5 characters from the file into a buffer
//    char buffer[7];
//    myFile.read(buffer, 6);

//    // End the buffer with a null terminating character
//    buffer[6] = 0;

//    // Output the contents read from the file and close it
//    cout << buffer << endl;

//    myFile.close();

//    return 0;
//}


//#include<iostream>
//#include<fstream>

//struct record {
//    char  code[6];
//    char name[20];
//    int i;
//} r;

//int main()
//{
//    std::fstream file("test.txt", std::ios::trunc | std::ios::in | std::ios::out | std::ios::binary);
//    if (!file) {
//        std::cout << "unable to open file";
//        exit(0);
//    }

//    std::cout << "enter character code, name and an int\n";

//    std::cin.getline(r.code, 6);
//    std::cin.getline(r.name, 20);
//    std::cin >> r.i;
//    file.write((char *)&r, sizeof(r));

//    std::cout << "\n\n" << file.tellg() << '\n' << file.tellp();

//    file.seekg(3);
//    std::cout << "\n\n" << file.tellg() << '\n' << file.tellp();

//    file.seekp(5);
//    std::cout << "\n\n" << file.tellg() << '\n' << file.tellp();


