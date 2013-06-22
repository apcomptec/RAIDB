#ifndef IP_H
#define IP_H
#include <QString>
#include <dataStructure/DLL.h>

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
    DLL<int>* _numUsedBlocks;
    //Tamaño de bloque
    int _sizeBlock;

public:
    //CONSTRUCTOR Y DESTRUCTOR
    IP(QString pIP, int pNumLSS, int pSize, int pSizeBlock, DLL<int> *pNumUsedBlock);
    ~IP();

    //Metodos de modificacion
    void setIP(QString);
    void setNumLSS(int);
    void setSize(int);
    void setNumUsedBlock(int pNum);
    void setSizeBlock(int);

    //Metodo de obtencion de datos
    QString getIP();
    int getNumLSS();
    int getSize();
    int getNumUsedBlock();
    int getSizeBlock();

    //Metodo de calculo de numero de bloques
    void calcNumOfBlocks();
};

#endif // IP_H
