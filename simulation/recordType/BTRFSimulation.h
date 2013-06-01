#ifndef BTRFSIMULATION_H
#define BTRFSIMULATION_H

#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "simulation/ARecordSimulable.h"

class BTRFSimulation: public ARecordSimulable
{
public:

    BTRFSimulation(BTRecordFileMetadata * const pMetadata);

    virtual void insert(DLL<IRecordDataType *> *pList);

private:
//    BTRecordFile *_file;
};

#endif // BTRFSIMULATION_H
