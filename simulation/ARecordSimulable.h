#ifndef ARECORDSIMULABLE_H
#define ARECORDSIMULABLE_H

#include "fileHandling/IMetadata.h"
#include "fileHandling/IRecordFile.h"

class ARecordSimulable
{
public:
    ARecordSimulable();

    virtual void insert();
    void dataStructureByUser();

    IMetadata* getMetadata();
    void setMetadata(IMetadata * const pMetadata);

private:

    const IRecordFile *_file;

    virtual unsigned short computeRecordSize() const = 0;
};

#endif // ARECORDSIMULABLE_H
