/*******************************************************************************
 * File: ISimulable.h
 * Author: Brallan Aguilar
 * Description: Interfaz que define cómo se realizará una simulación. Esta
 * abarca la simulación en red y local.
 ******************************************************************************/

#ifndef ASIMULABLE_H
#define ASIMULABLE_H

#include "fileHandling/IMetadata.h"

class ISimulable
{
public:

    /**
     * @brief createFile
     */
    virtual void createFile() = 0;

    /**
     * @brief insertRecord
     */
    virtual void insertRecord() = 0;

    /**
     * @brief deleteRecord
     */
    virtual void deleteRecord() = 0;

    /**
     * @brief searchRecord
     */
    virtual void searchRecord() = 0;

private:

    /**
     * @brief mainMenu Menú principal cuando se comience la simulación
     */
    virtual void mainMenu() = 0;

    /**
     * @brief createMetadata Se encarga de reconstruir los metadatos del
     * archivo
     */
    virtual IMetadata *createMetadata() const = 0;
};

#endif // ASIMULABLE_H
