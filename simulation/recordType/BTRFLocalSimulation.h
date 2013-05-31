#ifndef BTRFLOCALSIMULATION_H
#define BTRFLOCALSIMULATION_H

#include "simulation/LocalSimulation.h"
#include "simulation/recordType/BTRFSimulation.h"

class BTRFLocalSimulation: public LocalSimulation
{
public:

    /**
     * @brief BTRLocalSimulation
     */
    BTRFLocalSimulation();

// -----------------------------------------------------------------------------
// MÉTODOS PÚBLICOS DE LA CLASE ABSTRACTA ASIMULABLE
// -----------------------------------------------------------------------------
    virtual void createFile();

    virtual void insertRecord();

    virtual void deleteRecord();

    virtual void searchRecord();
// -----------------------------------------------------------------------------

private:

    /**
     * @brief _fileSimulation
     */
    BTRFSimulation *_fileSimulation;

// -----------------------------------------------------------------------------
// MÉTODO PRIVADO DE LA CLASE ABSTRACTA ASIMULABLE
// -----------------------------------------------------------------------------
    virtual BTRecordFileMetadata *createMetadata() const;
    virtual void mainMenu();
// -----------------------------------------------------------------------------

    IMetadata *getMetadata() const;
};

#endif // BTRFLOCALSIMULATION_H
