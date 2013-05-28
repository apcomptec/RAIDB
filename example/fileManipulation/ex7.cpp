// Extraído de http://c.conclase.net/curso/?cap=039

/*
 * Hasta ahora sólo hemos trabajado con los ficheros secuencialmente, es decir,
 * empezamos a leer o a escribir desde el principio, y avanzamos a medida que
 * leemos o escribimos en ellos.Otra característica importante de los ficheros
 * es la posibilidad de trabajar con ellos haciendo acceso aleatorio, es decir,
 * poder hacer lecturas o escrituras en cualquier punto del fichero. Para eso
 * disponemos de las funciones seekp y seekg, que permiten cambiar la posición
 * del fichero en la que se hará la siguiente escritura o lectura. La 'p' es de
 * put y la 'g' de get, es decir escritura y lectura, respectivamente.
 * Otro par de funciones relacionadas con el acceso aleatorio son tellp y tellg,
 * que sirven para saber en qué posición del fichero nos encontramos.
 * La función seekg nos permite acceder a cualquier punto del fichero, no tiene
 * por qué ser exactamente al principio de un registro, la resolución de las
 * funciones seek es de un byte.
 * Cuando trabajemos con nuestros propios streams para nuestras clases,
 * derivándolas de ifstream, ofstream o fstream, es posible que nos convenga
 * sobrecargar las funciones seek y tell para que trabajen a nivel de registro,
 * en lugar de hacerlo a nivel de byte.
 * La función seekp nos permite sobrescribir o modificar registros en un fichero
 * de acceso aleatorio de salida. La función tellp es análoga a tellg, pero para
 * ficheros de salida.
 */

#include <fstream>
#include <iostream>

using namespace std;

int ex7()
{
    const char* loc = "example/fileManipulation/ex7.dat";

    const char SIZE = 11;

    char mes[][SIZE] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre",
                        "Diciembre"
                       };
    char cad[SIZE];

    ofstream fsalida(loc, ios::out | ios::binary);

    // Crear fichero con los nombres de los meses:
    cout << "Crear archivo de nombres de meses:" << endl;
    for (int i = 0; i < 12; i++)
        fsalida.write(mes[i], SIZE);
    fsalida.close();

    ifstream fentrada(loc, ios::in | ios::binary);

    // Acceso secuencial:
    cout << "\nAcceso secuencial:" << endl;
    fentrada.read(cad, SIZE);
    do {
        cout << cad << endl;
        fentrada.read(cad, SIZE);
    } while (!fentrada.eof());

    fentrada.clear();

    // Acceso aleatorio:
    cout << "\nAcceso aleatorio:" << endl;
    for (int i = 11; i >= 0; i--) {
        fentrada.seekg(SIZE * i, ios::beg);
        fentrada.read(cad, SIZE);
        cout << cad << endl;
    }

    // Calcular el número de elementos
    // almacenados en un fichero:
    // ir al final del fichero
    fentrada.seekg(0, ios::end);

    // leer la posición actual
    streampos pos = fentrada.tellg();

    // El número de registros es el tamaño en
    // bytes dividido entre el tamaño del registro:
    cout << "\nNúmero de registros: " << pos / SIZE << endl;
    fentrada.close();

    char a  = 5;
    cout << "sizeof(a): " << sizeof(a) << "\n";

    char *b = &a;
    cout << "sizeof(b): " << sizeof(b) << "\n";
    cout << "sizeof(*b): " << sizeof(*b) << "\n";
    cout << "sizeof(&b): " << sizeof(&b) << "\n";

    int r = 3;
    int &j = r;
    cout << "r: " << r << " j: " << j << "\n";
    r++;
    cout << "r: " << r << " j: " << j << "\n";
    j++;
    cout << "r: " << r << " j: " << j << "\n";
    return 0;
}
