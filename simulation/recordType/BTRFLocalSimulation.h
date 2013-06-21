#ifndef BTRFLOCALSIMULATION_H
#define BTRFLOCALSIMULATION_H

#include "simulation/LocalSimulation.h"
#include "simulation/recordType/BTRFSimulation.h"
#include "dataStructure/n_aryrecordfile.h"
//#include "dataStructure/IN_aryNode.h"

class BTRFLocalSimulation: public LocalSimulation
{
public:

    /**
     * @brief BTRLocalSimulation
     */
    BTRFLocalSimulation();

    virtual void mainMenu();

private:

    /**
     * @brief _fileSimulation
     */
    BTRFSimulation *_fileSimulation;

    N_aryRecordFile *_fileSystem;

    /**
     * @brief _currentFolder puntero al directorio actual
     */
    N_aryRecordFileNode<QString> *_currentFolder;

// -----------------------------------------------------------------------------
// MÉTODOS PARA EDITAR EL ARCHIVO
// -----------------------------------------------------------------------------
    void createFile();

    void selectFile();

    void insertRecord();

    void deleteRecord();

    void searchRecord();
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// MÉTODOS PARA EDITAR DIRECTORIOS
// -----------------------------------------------------------------------------
    void showFolderContent();
    void createFolder();
    void deleteFolder();
    void changeFolder();
// -----------------------------------------------------------------------------

    virtual void fileHandling();
    virtual void directoryHandling();


// -----------------------------------------------------------------------------
// MÉTODO
// -----------------------------------------------------------------------------
    BTRecordFileMetadata *createMetadata() const;
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// MÉTODOS AUXILIARES
// -----------------------------------------------------------------------------
    IMetadata *getMetadata() const;
    void modifyFile();
// -----------------------------------------------------------------------------

};

#endif // BTRFLOCALSIMULATION_H
