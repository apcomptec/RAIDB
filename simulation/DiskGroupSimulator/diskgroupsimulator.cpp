#include "diskgroupsimulator.h"

DiskGroupSimulator::DiskGroupSimulator()
{
    this->_listDisk = new DLL<QString>();
    this->numDiskComplete = this->numDiskIncomplete = 0;
    initSimulator();
}

void DiskGroupSimulator::insertDisk(QString pID)
{
    this->_listDisk->insertAtBack(pID);
}

void DiskGroupSimulator::removeDisk(QString pID)
{
    this->_listDisk->removeSpecific(pID);
}

DLLNode<QString>* DiskGroupSimulator::searchDisk(QString pID)
{
    return this->_listDisk->searchInOrder(pID);
}

void DiskGroupSimulator::calculateNumOfListDisk()
{
    int numDisk = this->_listDisk->getSize();

    if((numDisk % NUMMAXDISK) == 0)
    {
        this->numDiskComplete = numDisk / NUMMAXDISK;
    }else
    {
        numDiskComplete = numDisk / NUMMAXDISK;
        numDiskIncomplete = numDisk - (numDiskComplete * NUMMAXDISK);
    }
}

void DiskGroupSimulator::initSimulator()
{
    char entry;

    while(entry != '0')
    {
        std::cout << "Opciones a realizar (salir 0): " << std::endl;
        std::cout << "1. Insertar Disk" << std::endl;
        std::cout << "2. Eliminar Disk" << std::endl;
        std::cout << "3. Buscar Disk" << std::endl;
        std::cout << "4. Organizar Disks" << std::endl;
        std::cout << "5. Mostrar Organizacion de Disk" << std::endl;
        std::cout << ">> ";
        std::cin >> entry;

        this->verifyOption(entry);
    }
}

void DiskGroupSimulator::verifyOption(char pEntry)
{
    std::string message;
    if(pEntry == '1')
    {
        std::cout << ">> ";
        std::cin >> message;
        this->insertDisk(Converter::fromStringToQString(message));
    }else if(pEntry == '2')
    {
        std::cin >> message;
        this->removeDisk(Converter::fromStringToQString(message));
    }else if(pEntry == '3')
    {
        std::cin >> message;
        this->searchDisk(Converter::fromStringToQString(message));
    }else if(pEntry == '4')
    {
        this->organiseDisk();
    }else if(pEntry == '5')
    {
    }
}

void DiskGroupSimulator::organiseDisk()
{
    this->calculateNumOfListDisk();
    std::cout << "Lista discos completos al maximo: " << this->numDiskComplete << std::endl;
    std::cout << "Discos restantes: " << this->numDiskIncomplete << std::endl;
}
