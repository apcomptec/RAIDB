#include <iomanip>
#include "simulation/ARecordSimulable.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"

ARecordSimulable::ARecordSimulable(IRecordFile * const pFile)
    : _file(pFile)
{
    // vacío
}

void ARecordSimulable::insert()
{
}

void ARecordSimulable::dataStructureByUser()
{
    std::cout << "Los registros tienen la siguiente estructura: \n\n";

    DLLNode<IRecordDataType *> *current =
        getMetadata()->getRecordStruct()->getHeadPtr();

    char headerName;
    bool flag = true;

    do {
        headerName =
            *dynamic_cast<RecordDataType<char>*>
            (current->getData())->getDataPtr();

        if (headerName == BTRecordFileMetadata::STRING) {
            std::cout << "string";
        } else if (headerName == BTRecordFileMetadata::CHAR) {
            std::cout << "char";
        } else if (headerName == BTRecordFileMetadata::SHORT) {
            std::cout << "short";
        } else if (headerName == BTRecordFileMetadata::INT) {
            std::cout << "int";
        } else if (headerName == BTRecordFileMetadata::DOUBLE) {
            std::cout << "double";
        } else if (headerName == BTRecordFileMetadata::BOOL) {
            std::cout << "bool";
        } else {
            flag = false;
            std::cout << "El tipo de dato no es soportado";
        }

        if (flag) {
            std::cout << ": " << current->getData()->getName() << " ["
                      << current->getData()->getSize() << "B]";
        }

        current = current->getNextPtr();
        std::cout << "\n";
    } while (current != nullptr);

    std::cout << "\n";
}

IMetadata *ARecordSimulable::getMetadata()
{
    return _file->getMetadata();
}


IRecord *ARecordSimulable::getFile()
{
//    return _file;
}
