#ifndef RAID0_H
#define RAID0_H
#include "IRaid.h"

class Raid0: public IRaid
{
public:
    Raid0();
    ~Raid0();
    bool write();
    bool read();
    bool modify();
    bool erase();
    bool stripe();
};

#endif // RAID0_H
