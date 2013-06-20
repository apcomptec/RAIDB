#include "randomnumber.h"

RandomNumber::RandomNumber(unsigned short pLowerLimit, unsigned short pHigherLimit)
{
    this->_lowerLimit = pLowerLimit;
    this->_higherLimit = pHigherLimit;
    srand( time( NULL ) );
}

RandomNumber::~RandomNumber()
{
}

unsigned short RandomNumber::generateRandom()
{
    return rand() % (_higherLimit - _lowerLimit) + _lowerLimit;
}

unsigned short RandomNumber::getHigherLimit() const
{
    return _higherLimit;
}

void RandomNumber::setHigherLimit(unsigned short higherLimit)
{
    _higherLimit = higherLimit;
}

unsigned short RandomNumber::getLowerLimit() const
{
    return _lowerLimit;
}

void RandomNumber::setLowerLimit(unsigned short lowerLimit)
{
    _lowerLimit = lowerLimit;
}
