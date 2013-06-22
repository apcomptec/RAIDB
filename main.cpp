#include <fstream>
#include <iostream>
#include <string>
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"
#include "util/Converter.h"
#include "raid/Disk.h"
#include "util/parser/XMLParser.h"
#include "dataStructure/n_aryrecordfile.h"
#include <bitset>
#include "simulation/recordType/BTRFLocalSimulation.h"
#include "util/Encryption.h"

using namespace std;

int main()
{
//    Converter *d = new Converter();
//    d->fromDoubleString2BinaryString("7.2");
//    d->fromBinaryString2DoubleString("111101");
//    Encryption *p = new Encryption();
//    p->passwordEncryption("Daniel");
//    std::cout << read(5);
//    std::cout << read(90);


//    // read a file into memory
//    #include <iostream>     // std::cout
//    #include <fstream>      // std::ifstream


//      std::ifstream is ("test.txt", std::ifstream::binary);
//      if (is) {
//        // get length of file:
//        is.seekg (0, is.end);
//        int length = is.tellg();
//        is.seekg (0, is.beg);

//        char * buffer = new char [length];

//        std::cout << "Reading " << length << " characters... ";
//        // read data as a block:
//        is.read (buffer,length);

//        if (is)
//          std::cout << "all characters read successfully.";
//        else
//          std::cout << "error: only " << is.gcount() << " could be read";
//        is.close();

//        std::cout << buffer;

//        // ...buffer contains the entire file...

//        delete[] buffer;
//      }
//      return 0;

//    Disk *disk = new Disk(1, 7);
//    disk->write(0, "adihfalhdflaksdhfkjahsdflkahkjlfhadsfhalkdhsfkljahdfkjahsdjfhasdfhjlkadshfsadhfklsahdfklhasdjfhasldhfkasdhflkasdhflkahsfkljasdhfjkahdskfjhasdfha39488935   f adsfahdskjfhalsdhflkasdhfjahsflahf934r9832459jfdalefhlkadadihfalhdflaksdhfkjahsdflkahkjlfhadsfhalkdhsfkljahdfkjahsdjfhasdfhjlkadshfsadhfklsahdfklhasdjfhasldhfkasdhflkasdhflkahsfkljasdhfjkahdskfjhasdfha39488935   f adsfahdskjfhalsdhflkasdhfjahsflahf934r9832459jfdalefhlkadshfshf" );

//    disk->read(0, 300);
//    disk->read(0, 350);

//    disk->write(0, "3324782374y2yStarting /home/brallan/qtCreator/build-RAIDB-Desktop_Qt_4_8_4_in_PATH_System-Release/RAIDB.../home/brallan/qtCreator/build-RAIDB-Desktop_Qt_4_8_4_in_PATH_System-Release/RAIDB exited with code 0hehhd87y3r87y4372635764736yr7483yr7824yr872y7e32he72yew7823ye78y24837e723ye47ye723hshy8778323874732593543j85u2834u589u248u58923u458923u4ejd832jsd3js823j489er2834jr824j895682345823u45823u458923ualefhlkadadihfalhdflaksdhfkjahsdflkahkjlfhadsfhalkdhsfkljahdfkjahsdjfhasdfhjlkadshfsadhfklsahdfklhasdjfhasldhfkasdhflkasdhflkahsfkljasdhfjkahdskfjhasdfha39488935   f adsfahdskjfhalsdhflkasdhfjahsflahf934r9832459jfdalefhlkadshfshf" );

//    std::cout << disk->read(0, 700);

//    XMLParser *p = new XMLParser();
////    p->generateBackUp(3,2,3);


////// *****************************************************************************
////// LECTURA DEL ARBOL DE CARPETA Y ARCHIVO N-ARIO
////// *****************************************************************************
//    N_aryRecordFile* nTree = new N_aryRecordFile();
//    nTree->insertDirPtr("home");
//    nTree->insertDirPtr("tmp");
//    nTree->insertDirPtr("bin");
//    nTree->insertDirPtr("jose", "/home/");
//    nTree->insertDirPtr("daniel", "/home/");
//    nTree->insertDirPtr("badilla", "/home/");
//    nTree->insertDirPtr("dir", "/home/jose/");
//    nTree->insertDirPtr("nueva", "/home/daniel/");

//    std::cout << "\nImpresion del arbol" << std::endl;
//    nTree->printTree();

//    nTree->deleteDirPtr("/home/daniel/nueva/");
//    std::cout << "\nImpresion del arbol" << std::endl;
//    nTree->printTree();

//    std::cout << "\n" << std::endl;
//    nTree->printContentOf("/home/");
//    p->generateBackUp(3,2,3,nTree->getRoot());
//    std::cout << "Fin de la ejecución" << std::endl;

// *****************************************************************************
// LECTURA DEL ARBOL DE CARPETA Y ARCHIVO N-ARIO
// *****************************************************************************


//// *****************************************************************************
//// PRUEBA PARA HACER CONVERSIONES DE DATOS DE BINARIO A NORMAL Y VICEVERSA
//// *****************************************************************************
//       Converter *c = new Converter();
//        Converter *c = new Converter();
//    cout << "--------------------" << endl;
//    cout << c->fromString2Short("3") << endl;
//    cout << "--------------------" << endl;
//    c->binaryToDecimal("00111");
//    cout << "--------------------" << endl;
//    c->decimalToBinary("7");
//    cout << "--------------------" << endl;
//    c->binaryToString("01001000");
//    cout << "--------------------" << endl;
//    c->stringToBinary("Daniel");
//    cout << "--------------------" << endl;

//    c->verificaValidezDouble("18.5"); // prueba si es double
//    c->verificaValidezDouble("A");    // prueba si es double
//    c->verificaValidezDouble("185");  // prueba si es double

//    c->fromString2Double("0.6");
//    c->fromDouble2String(456.7);
//    c->fromDoubleString2BinaryString("7.3");
//    c->fromString2Int("25");
//        c->fromBinaryString2DoubleString("0100100100000001");

//        c->fromDoubleString2BinaryString("7.3");

//    std::bitset<64> Bitset64(std::string("0000010100100100111001100010000100000010100001010011100110011111"));

//       double value = Bitset64.to_ulong();
//       std::cout << value;
//// *****************************************************************************
//// PRUEBA SIMULADOR LOCAL
//// *****************************************************************************

    new BTRFLocalSimulation();

//    std::cout << std::setw(20) << "Hola" << std::setw(6) << "jaja" << std::setw(1) << "LOLO";
//    std::string name = "12", owner = "u";
//   DLL<IRecordDataType*> *record = new DLL<IRecordDataType*>();
//    BTRecordFileMetadata *metadata = new BTRecordFileMetadata(name, owner, record);
//    std::cout << "Dun";
//        std::cout << "------------------------------------------------------\n|";
//        std::cout << "   Tipo   |"
//                  << "          Nombre          |"
//                  << "  Tamaño (B)  |\n";
//        std::cout << "------------------------------------------------------\n";

//        std::cout << std::left << std::setw(4) << "Hola" << std::setw(13) << "jaja\n";

// ############################################################################
// ESCRITURA DE REGISTROS EN EL DISCO
// ############################################################################

// *****************************************************************************
// ESTRUCTURA METADATOS
// *****************************************************************************
//    DLL<IRecordDataType*> *list1 = new DLL<IRecordDataType*>();
//    std::string name1 = "DAV";
//    char dataType1 = '0';
//    unsigned short size1 = 4;
//    RecordDataType<char> *data1 = new RecordDataType<char>(name1, dataType1, size1);
//    list1->insertAtBack(data1);

//    std::string name2 = "IMO";
//    char dataType2 = '3';
//    unsigned short size2 = 2;
//    RecordDataType<char> *data2 = new RecordDataType<char>(name2, dataType2, size2);
//    list1->insertAtBack(data2);

//    BTRecordFileMetadata *metadata = new BTRecordFileMetadata("Fil", "YO", list1);

//// *****************************************************************************
//// CREACIÓN ARCHIVO BINARIO
//// *****************************************************************************
//    BTRecordFile *file = new BTRecordFile(metadata);

//   file->saveMetadata2Disk();    // sirve para la metadata
//   file->loadMetadata();         // sirve para la metadata

//// *****************************************************************************
//// REGISTRO 1
//// *****************************************************************************
//   {     // CAMPO 'APELLIDO'
//        std::string apellido1 = "H";
//        RecordDataType<std::string> *apellido1Data =
//            new RecordDataType<std::string>(name1, apellido1 , size1);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        DLL<IRecordDataType *> *record1 = new DLL<IRecordDataType*>();
//        record1->insertAtBack(apellido1Data);

//        // CAMPO 'GÉNERO'
//        std::string genero1 = "7";
//        RecordDataType<std::string> *genero1Data =
//            new RecordDataType<std::string>(name2, genero1 , size2);

////        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        record1->insertAtBack(genero1Data);

////        // ESCRIBE A DISCO EL REGISTRO 1
//        file->insertRecord2Disk(record1);
//    }

//// *****************************************************************************
//// REGISTRO 2
//// *****************************************************************************
//    {
//        // CAMPO 'APELLIDO'
//        std::string apellido2 = "Z";
//        RecordDataType<std::string> *apellido2Data =
//            new RecordDataType<std::string>(name1, apellido2 , size1);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        DLL<IRecordDataType *> *record2 = new DLL<IRecordDataType*>();
//        record2->insertAtBack(apellido2Data);

//        // CAMPO 'GÉNERO'
//        std::string genero2 = "1";
//        RecordDataType<std::string> *genero2Data =
//            new RecordDataType<std::string>(name2, genero2 , size2);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        record2->insertAtBack(genero2Data);

////        // SE INSERTA EL REGISTRO 2 EN EL ARCHIVO DE REGISTROS
////        file->insertRecord(record2);

//        // ESCRIBE A DISCO EL REGISTRO 2
//        file->insertRecord2Disk(record2);
//    }

//// *****************************************************************************
//// REGISTRO 3
//// *****************************************************************************
//    {
//        // CAMPO 'APELLIDO'
//        std::string apellido3 = "L";
//        RecordDataType<std::string> *apellido3Data =
//            new RecordDataType<std::string>(name1, apellido3 , size1);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        DLL<IRecordDataType *> *record3 = new DLL<IRecordDataType*>();
//        record3->insertAtBack(apellido3Data);

//        // CAMPO 'GÉNERO'
//        std::string genero3 = "9";
//        RecordDataType<std::string> *genero3Data =
//            new RecordDataType<std::string>(name2, genero3 , size2);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        record3->insertAtBack(genero3Data);

//        // ESCRIBE A DISCO EL REGISTRO 1
//        file->insertRecord2Disk(record3);

//    }

//// *****************************************************************************
//// REGISTRO 4
//// *****************************************************************************
//    {
//        // CAMPO 'APELLIDO'
//        std::string apellido4 = "R";
//        RecordDataType<std::string> *apellido4Data =
//            new RecordDataType<std::string>(name1, apellido4 , size1);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        DLL<IRecordDataType *> *record4 = new DLL<IRecordDataType*>();
//        record4->insertAtBack(apellido4Data);

//        // CAMPO 'GÉNERO'
//        std::string genero4 = "0";
//        RecordDataType<std::string> *genero4Data =
//            new RecordDataType<std::string>(name2, genero4 , size2);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        record4->insertAtBack(genero4Data);

//        // SE INSERTA EL REGISTRO 2 EN EL ARCHIVO DE REGISTROS
////        //file->insertRecord(record4);

//        // ESCRIBE A DISCO EL REGISTRO 2
//        file->insertRecord2Disk(record4);
//    }

//// *****************************************************************************
//// REGISTRO 5
//// *****************************************************************************
//    {
//        // CAMPO 'APELLIDO'
//        std::string apellido5 = "P";
//        RecordDataType<std::string> *apellido5Data =
//            new RecordDataType<std::string>(name1, apellido5 , size1);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        DLL<IRecordDataType *> *record5 = new DLL<IRecordDataType*>();
//        record5->insertAtBack(apellido5Data);

//        // CAMPO 'GÉNERO'
//        std::string genero5 = "6";
//        RecordDataType<std::string> *genero5Data =
//            new RecordDataType<std::string>(name2, genero5 , size2);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        record5->insertAtBack(genero5Data);

//        // SE INSERTA EL REGISTRO 2 EN EL ARCHIVO DE REGISTROS
////        file->insertRecord(record5);

//        // ESCRIBE A DISCO EL REGISTRO 2
//        file->insertRecord2Disk(record5);
//    }

//// *****************************************************************************
//// REGISTRO 6
//// *****************************************************************************
//    {
//        // CAMPO 'APELLIDO'
//        std::string apellido6 = "Y";
//        RecordDataType<std::string> *apellido6Data =
//            new RecordDataType<std::string>(name1, apellido6 , size1);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        DLL<IRecordDataType *> *record6 = new DLL<IRecordDataType*>();
//        record6->insertAtBack(apellido6Data);

//        // CAMPO 'GÉNERO'
//        std::string genero6 = "1";
//        RecordDataType<std::string> *genero6Data =
//            new RecordDataType<std::string>(name2, genero6 , size2);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        record6->insertAtBack(genero6Data);

//        // ESCRIBE A DISCO EL REGISTRO 1
//        file->insertRecord2Disk(record6);

//    }

//// *****************************************************************************
//// REGISTRO 7
//// *****************************************************************************
//    {
//        // CAMPO 'APELLIDO'
//        std::string apellido7 = "q";
//        RecordDataType<std::string> *apellido7Data =
//            new RecordDataType<std::string>(name1, apellido7 , size1);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        DLL<IRecordDataType *> *record7 = new DLL<IRecordDataType*>();
//        record7->insertAtBack(apellido7Data);

//        // CAMPO 'GÉNERO'
//        std::string genero7 = "8";
//        RecordDataType<std::string> *genero7Data =
//            new RecordDataType<std::string>(name2, genero7 , size2);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        record7->insertAtBack(genero7Data);

////        // SE INSERTA EL REGISTRO 2 EN EL ARCHIVO DE REGISTROS
////        file->insertRecord(record7);

//        // ESCRIBE A DISCO EL REGISTRO 2
//        file->insertRecord2Disk(record7);
//    }

//    file->readALLRecordsFromDisk();
}
