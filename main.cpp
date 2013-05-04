#include <iostream>
#include "XMLParser.h"

using namespace std;

int main()
{
    XMLParser *p = new XMLParser();
    p->writeFile();

    cout << "Hello World!" << endl;
    return 0;
}
