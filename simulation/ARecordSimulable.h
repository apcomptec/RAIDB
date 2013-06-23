#ifndef ARECORDSIMULABLE_H
#define ARECORDSIMULABLE_H

#include "fileHandling/IMetadata.h"
#include "fileHandling/IRecordFile.h"

class ARecordSimulable
{
public:
    ARecordSimulable(IRecordFile * const pFile);

    /**
     * @brief insert inserta nuevos registros al archivo
     */
    void insertRecord();

    void readRecord(unsigned short pRecordNum);

    IMetadata *getMetadata();
    void setMetadata(IMetadata * const pMetadata);

    IRecordFile *getFile();
    void setFile(IRecordFile *pFile);

protected:
    IRecordFile * _file;
};

#endif // ARECORDSIMULABLE_H
