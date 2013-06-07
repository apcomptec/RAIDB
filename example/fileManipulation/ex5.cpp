// Extraído de http://c.conclase.net/curso/?cap=039
// Vamos a crear un fichero mediante un objeto de la clase ofstream, y
// posteriormente lo leeremos mediante un objeto de la clase ifstream

#include <iostream>
#include <fstream>

int ex5()
{
    const char SIZE = 18; // tamaño de lectura de la línea
    char cadena[SIZE]; // donde se almacena lo leído

    const char *loc = "example/fileManipulation/ex5.txt";

    // Crea un fichero de salida
    std::ofstream fs(loc);

    // Enviamos una cadena al fichero de salida:
    fs << "Hola, mundo jeje" << std::endl;
    // Cerrar el fichero,
    // para luego poder abrirlo para lectura:
    fs.close();

    // Abre un fichero de entrada
    std::ifstream fe(loc);

    // Leeremos mediante getline, si lo hiciéramos
    // mediante el operador << sólo leeríamos
    // parte de la cadena:
    fe.getline(cadena, SIZE);

    std::cout << cadena << std::endl;

    return 0;
}
