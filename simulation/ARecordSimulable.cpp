#include "simulation/ARecordSimulable.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"

ARecordSimulable::ARecordSimulable()
{

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

    do {
        headerName = *current->getData()->getName().c_str();

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
            std::cout << "El tipo de dato no es soportado";
        }

//                current = current->getNextPtr();
        current++;

    } while (current != nullptr);

    std::cout << "\n\n";
}

IMetadata *ARecordSimulable::getMetadata()
{
    return _file->getMetadata();
}
