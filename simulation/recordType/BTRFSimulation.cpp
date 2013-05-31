#include "BTRFSimulation.h"
#include "fileHandling/RecordDataType.h"

BTRFSimulation::BTRFSimulation(BTRecordFileMetadata * const pMetadata)
    : _file(new BTRecordFile(pMetadata))
{
    _file->getMetadata()->setRecordSize(computeRecordSize());
}

unsigned short BTRFSimulation::computeRecordSize() const
{
    // representa la cantidad de datos primarios en el registro que son padre,
    // hijo izquierdo y derecho
    const unsigned short NUMBER_OF_PRIMARY_DATA = 3;

    // indica el tamaño en bytes de los datos padre, hijo izquierdo e hijo
    // derecho en el registro
    const unsigned short PRIMARY_DATA = 4;

    // tamaño del registro
    unsigned short size = NUMBER_OF_PRIMARY_DATA * PRIMARY_DATA;

    DLLNode<IRecordDataType *> *currentDataByUser =
        _file->getMetadata()->getRecordStruct()->getHeadPtr();

    while (currentDataByUser != nullptr) {
        size += currentDataByUser->getData()->getSize();
        currentDataByUser++; // FIXME probar si sirve para pasar a siguiente nodo
    }

    return size;
}

void BTRFSimulation::insert(DLL<IRecordDataType *> *pList)
{
    _file->insertRecord(pList);
}
