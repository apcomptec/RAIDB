#include <iostream>
#include "fileHandling/RecordDataType.h"
#include <fstream>
#include "XMLParser.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::string c;
    int b = 3;
    c = "jojo";
    RecordDataType<int> fi(c, b);
    fi.getDataPtr();

    XMLParser *p = new XMLParser();
    p->writeFile();

    cout << "Hello World!" << endl;
    return 0;
    std::ofstream ofs("ouput.img", std::ios::binary | std::ios::out);
    ofs.seekp((1024 << 20) - 1);
    ofs.write("", 1);

    return 0;
}


