#include "BTRFLocalSimulation.h"

BTRFLocalSimulation::BTRFLocalSimulation()
    : _fileSystem(new N_aryRecordFile()),
      _currentFolder(
          dynamic_cast<N_aryRecordFileNode<QString>*>(_fileSystem->getRoot()))
{
    mainMenu();
}

void BTRFLocalSimulation::createFile()
{
    BTRecordFileMetadata *metadata = createMetadata();
    if (metadata != nullptr) {
        _fileSimulation = new BTRFSimulation(metadata);
        _currentFolder->addRecordFilePtr(_fileSimulation->getFile());
        _fileSystem->printTree();
        _fileSimulation->dataStructureByUser();
    } else {
        std::cout << "El archivo no fue creado\n";
    }
}

void BTRFLocalSimulation::editFile()
{
    std::string name;
    IRecordFile *file;

    std::cout << "Nombre del archivo: ";
    std::cin >> name;

    file = _currentFolder->searchRecordFilePtr(name);

    if (file != nullptr) {
        char option;

        std::cout << "Seleccione lo que quiere hacer:\n"
                  " 1. Insertar registro\n"
                  " 2. Borrar registro\n"
                  " 3. Modificar registro\n"
                  " 4. Buscar registro\n";

        std::cin >> option;

        switch (option) {
        case '0':
            break;
        case '1':
            insertRecord();
        default:
            break;
        }
    } else {

    }
}

void BTRFLocalSimulation::insertRecord()
{
    DLLNode<IRecordDataType*> *current =
        getMetadata()->getRecordStruct()->getHeadPtr();

    DLL<IRecordDataType *> *dataList = new DLL<IRecordDataType*>();

    std::cout << "Registro #" << getMetadata()->getNumberOfRecords() << "\n";

    std::string name, data;
    unsigned short size;
    while (current != nullptr) {
        name = current->getData()->getName();
        size = current->getData()->getSize();

        std::cout << name << ": ";
        std::cin >> data;

        RecordDataType<std::string> *recordList =
            new RecordDataType<std::string>(name, data, size);

        dataList->insertAtBack(recordList);

        current = current->getNextPtr();
    }

    _fileSimulation->insertRecord(dataList);
    updateMetadata();
}

void BTRFLocalSimulation::deleteRecord() // TODO
{
}

void BTRFLocalSimulation::searchRecord()
{
}

void BTRFLocalSimulation::updateMetadata()
{
    dynamic_cast<BTRecordFile*>(_fileSimulation->getFile())->saveMetadata2Disk();
}

void BTRFLocalSimulation::showFolderContent() // TEST
{
    // IMPRIMIR DIRECTORIOS

    DLLNode<IN_aryNode<QString>*> *folder =
        _currentFolder->getChildList()->getHeadPtr();

    std::cout << "DIRECTORIOS:\n";
    while (folder != nullptr) {
        std::cout << folder->getData()->getData().toStdString() << "\n";
        folder = folder->getNextPtr();
    }

    // IMPRIMIR ARCHIVOS

    DLLNode<IRecordFile*> *file =
        _currentFolder->getRecordFileListPtr()->getHeadPtr();

    std::cout << "ARCHIVOS:\n";
    while (file != nullptr) {
        std::cout << file->getData()->getMetadata()->getFileName() << "\n";
        file = file->getNextPtr();
    }
}

void BTRFLocalSimulation::createFolder() // TODO
{
    std::string name;

    std::cout << "Escriba el nombre del directorio: ";
    std::cin >> name;

    _currentFolder->addChildPtr(
        new N_aryRecordFileNode<QString>(
            Converter::fromStringToQString(name)));
}

void BTRFLocalSimulation::deleteFolder() // TODO
{
}

void BTRFLocalSimulation::changeFolder()
{
    std::string path;
    QString qPath;
    IN_aryNode<QString> *tmp = nullptr; // ubicación temporal de la ruta objetivo

    std::cout << "Dirección solicitada: ";
    std::cin >> path;

    qPath = Converter::fromStringToQString(path);

    if (path == "/") { // va a la raíz
        tmp = _fileSystem->getRoot();
    } else if (path[0] == '/') { // inicia desde la raíz
        tmp = _fileSystem->searchDir(qPath.remove(0, 1));
    } else { // desde el directorio donde está el puntero actual
        tmp =
            dynamic_cast<N_aryRecordFileNode<QString>*>(_currentFolder)->
            searchDirInto(new N_aryRecordFileNode<QString>(qPath));
    }

    if (tmp != nullptr) { // sí existe la ruta
        std::cout << "Está en ";
        _currentFolder = dynamic_cast<N_aryRecordFileNode<QString>*>(tmp);
    } else { // hubo un error al ir a la ruta especificada
        std::cout << "Hubo un error al ir a ";
    }

    std::cout << path << "\n";
}

void BTRFLocalSimulation::fileHandling()
{
    char option;

    std::cout << "Seleccione una opción (0 para salir):\n"
              " 1. Crear un archivo\n"
              " 2. Editar un archivo\n"
              "> ";

    std::cin >> option;

    switch (option) {
    case '0':
        break;
    case '1':
        createFile();
        break;
    case '2':
        editFile();
        break;
    default:
        std::cout << "Escogió una opción incorrecta";
        break;
    }
}

void BTRFLocalSimulation::directoryHandling()
{
    char option;

    std::cout << "Escriba lo que quiere realizar en cuanto a directorios:\n"
              "  1. Crear un directorio\n"
              "  2. Borrar directorio\n"
              "  3. Ver directorio\n"
              "  4. Cambiar ubicación\n"
              " > ";

    std::cin >> option;

    switch (option) {
    case '1':
        createFolder();
        break;
    case '2':
        deleteFolder();
        break;
    case '3':
        showFolderContent();
        break;
    case '4':
        changeFolder();
        break;
    default:
        std::cout << "Escogió una opción incorrecta";
        break;
    }
}

BTRecordFileMetadata *BTRFLocalSimulation::createMetadata() const
{
    BTRecordFileMetadata *file = nullptr;
    unsigned short length;
    std::string name, fileName, owner = "LOCAL";
    char field, option;
    RecordDataType<char> *header;
    DLL<IRecordDataType*> *recordStruct = new DLL<IRecordDataType*>();

    // NOMBRE DE ARCHIVO
    std::cout << "Escriba el nombre del archivo: ";
    std::cin >> fileName;

    // CAMPOS DE REGISTRO

    std::cout << "Escriba los campos presentes en el registro "
              "(0 para salir):\n"
              "1. String\n"
              "2. Char\n"
              "3. Short\n"
              "4. Int\n"
              "5. Double\n"
              "6. Bool\n"
              "> ";

    std::cin >> option;

    if (option != '0') {
        while (option != '0') {
            if (option > '0' && option < '7') {
                std::cout << "\nNombre del campo: ";
                std::cin >> name;

                std::cout << "\nDefina su tamaño (en B): ";
                std::cin >> length;

                // resta uno a field para que sean compatibles con las
                // constantes ya declaradas
                field = option - 1;
                header = new RecordDataType<char>(name, field, length);
                recordStruct->insertAtBack(header);
            } else {
                std::cout << "No existe el tipo especificado";
            }

            std::cout << "Escriba los campos presentes en el registro "
                      << "(0 para salir):\n"
                      << "1. String\n"
                      << "2. Char\n"
                      << "3. Short\n"
                      << "4. Int\n"
                      << "5. Double\n"
                      << "6. Bool\n"
                      << "> ";

            std::cin >> option;
        }

        file = new BTRecordFileMetadata(fileName, owner, recordStruct);
    }

    return file;
}

void BTRFLocalSimulation::mainMenu()
{
    std::cout << "¡Bienvenido!\n\n";

    char option;
    do {
        std::cout << "Seleccione lo que desea hacer (0 para salir):\n"
                  << "   1. Manejo de directorios\n"
                  << "   2. Administrar archivos\n"
                  << "> ";

        std::cin >> option;

        std::cout << "\n";

        switch (option) {
        case '0':
            std::cout << "Bye!";
            break;
        case '1':
            directoryHandling();
            break;
        case '2':
            fileHandling();
            break;
        default:
            std::cout << "Escogió una opción incorrecta";
            break;
        }

        std::cout << "\n\n";
    } while (option != '0');
}

IMetadata *BTRFLocalSimulation::getMetadata() const
{
    return _fileSimulation->getMetadata();
}

void BTRFLocalSimulation::modifyFile()
{

}
