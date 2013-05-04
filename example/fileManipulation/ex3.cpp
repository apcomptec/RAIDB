// Extraído de http://stackoverflow.com/questions/7896035/c-make-a-file-of-a-specific-size
// Se encarga de crear un archivo de tamaño definido

#include <fstream>

int ex3()
{
    std::ofstream ofs("example/fileManipulation/hi.txt", std::ios::binary | std::ios::out);
    ofs.seekp((1024 << 10) - 1); // El 10 equivale a 2 ^ 10 B
    ofs.write("", 1);
}
