#ifndef BTRFSIMULATION_H
#define BTRFSIMULATION_H

#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "simulation/ARecordSimulable.h"

class BTRFSimulation: public ARecordSimulable
{
public:

    BTRFSimulation(BTRecordFileMetadata * const pMetadata);

    virtual void insertRecord(DLL<IRecordDataType *> *pList);
    virtual void read(unsigned short pRecordNum);
    virtual void deleteRecord(unsigned short pRecord);
};

#endif // BTRFSIMULATION_H
