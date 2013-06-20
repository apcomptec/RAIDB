#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class RandomNumber{

public:
    RandomNumber(unsigned short pLowerLimit, unsigned short pHigherLimit);
    ~RandomNumber();

    unsigned short generateRandom();   // Genera números aleatorios entre 2 números

    unsigned short getLowerLimit() const;
    void setLowerLimit(unsigned short lowerLimit);

    unsigned short getHigherLimit() const;
    void setHigherLimit(unsigned short higherLimit);

private:
    unsigned short _lowerLimit;         // valor mínimo
    unsigned short _higherLimit;        // valor máximo
};

#endif // RANDOMNUMBER_H
