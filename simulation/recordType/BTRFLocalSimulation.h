#ifndef BTRFLOCALSIMULATION_H
#define BTRFLOCALSIMULATION_H

#include "simulation/LocalSimulation.h"
#include "simulation/recordType/BTRFSimulation.h"
#include "dataStructure/n_aryrecordfile.h"

class BTRFLocalSimulation: public LocalSimulation
{
public:

    /**
     * @brief BTRLocalSimulation
     */
    BTRFLocalSimulation();

    N_aryRecordFile fileSystem;

// -----------------------------------------------------------------------------
// MÉTODOS PÚBLICOS DE LA CLASE ABSTRACTA ISIMULABLE
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
// MÉTODO PRIVADO DE LA INTEFAZ ISIMULABLE
// -----------------------------------------------------------------------------
    virtual BTRecordFileMetadata *createMetadata() const;
    virtual void mainMenu();
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// MÉTODOS AUXILIARES
// -----------------------------------------------------------------------------
        IMetadata *getMetadata() const;
        void modifyFile();
// -----------------------------------------------------------------------------

};

#endif // BTRFLOCALSIMULATION_H
