#include "BTRFSimulation.h"
#include "fileHandling/RecordDataType.h"

BTRFSimulation::BTRFSimulation(BTRecordFileMetadata * const pMetadata)
    : ARecordSimulable(new BTRecordFile(pMetadata))
{
    // vacío
}

void BTRFSimulation::insert(DLL<IRecordDataType *> *pList)
{
    _file->insertRecord(pList);
}
