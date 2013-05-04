//#include <iostream>
//#include<stdlib.h>
//#include<time.h>
//#include <fstream>
//#include <QString>
//#include <QCryptographicHash>

//using namespace std;


//char* getRandomString();

//int main()
//{

//    ofstream binaryFile("file.raw", ios::out | ios::binary);
//    char* myData;
//    for (int var = 0; var < 1024; ++var) {
//        myData = getRandomString();
//        cout << myData << endl;
//        binaryFile.write(myData, sizeof(char));
//        binaryFile.write("\n", sizeof(char));
//    }
//    binaryFile.close();
//    return 0;

////    QString blah = QString(QCryptographicHash::hash(("jejeje"),
////                           QCryptographicHash::Md5).toHex());

////    std::cout << blah.toStdString();

//}

//char* getRandomString()
//{
//    srand(time(NULL));
//    char strrnd[20];
//    for (int i = 0; i < 20; i++) {
//        strrnd[i] = 65 + (rand() % (90 - 65));
//    }
//    return strrnd;
//}

///* fwrite example : write buffer */
//#include <stdio.h>

//int main ()
//{
//    FILE * pFile;
//    long long buffer[] = { 'x' , 'y' , 'z' };
//    pFile = fopen ( "myfile.txt" , "wb" );
//    fwrite (buffer , 130000, sizeof(buffer) , pFile );
//    fclose (pFile);
//    return 0;
//}

#include <fstream>

int main()
{
    std::ofstream ofs("ouput.img", std::ios::binary | std::ios::out);
    ofs.seekp((1024<<20) - 1);
    ofs.write("", 1);
}
