#include <iostream>
#include "fileHandling/RecordDataType.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::string c;
    int b = 3;
    c = "jojo";
    RecordDataType<int> fi(c, b);
    fi.getDataPtr();

    return 0;
}
