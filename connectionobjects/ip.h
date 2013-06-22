#ifndef IP_H
#define IP_H
#include <QString>

/**
 * @brief The IP class
 */
class IP
{
private:
    //Atributo IP
    QString _ip;
    //Atributo numero de LSS
    int _numLSS;
    //Tamaño de disco
    int _sizeDisk;
    //Numero de bloques total
    int _numBlocks;
    //Numero de Bloques usados
    int _numUsedBlocks;
    //Tamaño de bloque
    int _sizeBlock;

public:
    //CONSTRUCTOR Y DESTRUCTOR
    IP(QString, int, int, int, int);
    ~IP();

    //Metodos de modificacion
    void setIP(QString);
    void setNumLSS(int);
    void setSize(int);
    void setNumUsedBlock(int);
    void setSizeBlock(int);

    //Metodo de obtencion de datos
    void getIP();
    void getNumLSS();
    void getSize();
    void getNumUsedBlock();
    void getSizeBlock();

    //Metodo de calculo de numero de bloques
    void calcNumOfBlocks();
};

#endif // IP_H
