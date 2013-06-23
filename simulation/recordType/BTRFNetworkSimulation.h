#ifndef BTRFNETWORKSIMULATION_H
#define BTRFNETWORKSIMULATION_H

#include "simulation/recordType/BTRFSimulation.h"

class BTRFNetworkSimulation
{
public:
    BTRFNetworkSimulation();

private:
    BTRFSimulation *_fileSimulation;
};

#endif // BTRFNETWORKSIMULATION_H
