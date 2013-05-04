#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <fstream>

using namespace std;


char* getRandomString();

int main()
{

    ofstream binaryFile ("file.raw", ios::out | ios::binary);
    char* myData;
    for (int var = 0; var < 1024; ++var) {
        myData = getRandomString();
        cout << myData << endl;
        binaryFile.write (myData, sizeof (char));
        binaryFile.write ("\n", sizeof (char));
    }
    binaryFile.close();
    return 0;
}

char* getRandomString(){
    srand(time(NULL));
    char strrnd[20];
    for(int i=0; i < 20; i++){
        strrnd[i] = 65 + (rand() % (90-65));
    }
    return strrnd;
}
