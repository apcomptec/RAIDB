#include <iomanip>
#include "simulation/ARecordSimulable.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"

ARecordSimulable::ARecordSimulable(IRecordFile * const pFile)
    : _file(pFile)
{
    // vacío
}

IMetadata *ARecordSimulable::getMetadata()
{
    return _file->getMetadata();
}

IRecordFile *ARecordSimulable::getFile()
{
    return _file;
}

void ARecordSimulable::setFile(IRecordFile *pFile)
{
    _file = pFile;
}
