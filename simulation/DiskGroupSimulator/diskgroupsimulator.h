#ifndef DISKGROUPSIMULATOR_H
#define DISKGROUPSIMULATOR_H
#include "dataStructure/DLL.h"
#include "util/Converter.h"
#include <string>
#include <QString>

#define NUMMAXDISK 4

class DiskGroupSimulator
{
private:
    DLL<QString>* _listDisk;
    int numDiskComplete, numDiskIncomplete;

public:
    DiskGroupSimulator();
    ~DiskGroupSimulator();

    void initSimulator();
    void insertDisk(QString);
    void removeDisk(QString);
    DLLNode<QString>* searchDisk(QString);

    void verifyOption(char);
    void organiseDisk();
    void calculateNumOfListDisk();
    QString getRandomDisk();

};

#endif // DISKGROUPSIMULATOR_H
