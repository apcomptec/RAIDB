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
     * @brief mainMenu Menú principal cuando se comience la simulación
     */
    virtual void mainMenu() = 0;

private:

    /**
     * @brief fileHandling
     */
    virtual void fileHandling() = 0;

    /**
     * @brief directoryHandling
     */
    virtual void directoryHandling() = 0;
};

#endif // ASIMULABLE_H
