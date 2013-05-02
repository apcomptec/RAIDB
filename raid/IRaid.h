/*******************************************************************************
 * File: IRaid.h
 * Author: Brallan Aguilar
 * Description: Interfaz para manejo de Raid
 * Reference:
 ******************************************************************************/

#ifndef IRAID_H
#define IRAID_H

class IRaid
{
public:
    virtual bool write() = 0;
    virtual bool read() = 0;
    virtual bool modify() = 0;
    virtual bool erase() = 0;
    virtual bool stripe() = 0;
};

#endif // IRAID_H
