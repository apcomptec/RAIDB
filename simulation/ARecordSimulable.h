#ifndef ARECORDSIMULABLE_H
#define ARECORDSIMULABLE_H

#include "fileHandling/IMetadata.h"
#include "fileHandling/IRecordFile.h"

class ARecordSimulable
{
public:
    ARecordSimulable(IRecordFile * const pFile);

    virtual void insert();
    void dataStructureByUser();

    IMetadata *getMetadata();
    void setMetadata(IMetadata * const pMetadata);

    IRecordFile *getFile();

protected:
    IRecordFile * const _file;
};

#endif // ARECORDSIMULABLE_H
