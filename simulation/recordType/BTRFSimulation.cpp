#include "BTRFSimulation.h"
#include "fileHandling/RecordDataType.h"

BTRFSimulation::BTRFSimulation(BTRecordFileMetadata * const pMetadata)
    : ARecordSimulable(new BTRecordFile(pMetadata))
{
    // guarda los metadatos en el disco
    dynamic_cast<BTRecordFile*>(_file)->saveMetadata2Disk();
}

void BTRFSimulation::insertRecord(DLL<IRecordDataType *> *pList)
{
    _file->insertRecord(pList);
}

void BTRFSimulation::read(unsigned short pRecordNum)
{
    _file->readRecord(pRecordNum);
}

void BTRFSimulation::deleteRecord(unsigned short pRecord)
{
    _file->deleteRecord(pRecord);
}
