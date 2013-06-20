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
    _fileSimulation = new BTRFSimulation(createMetadata());
    _fileSystem->insertFilePtr("Root", _fileSimulation->getFile());
//    _currentFolder =
//        dynamic_cast<N_aryRecordFileNode<QString>*>(_fileSystem.getRoot());
    _fileSystem->printTree();
    _fileSimulation->dataStructureByUser();
}

void BTRFLocalSimulation::insertRecord()
{
    DLLNode<IRecordDataType*> *current =
        getMetadata()->getRecordStruct()->getHeadPtr();

    DLL<IRecordDataType *> *dataList = new DLL<IRecordDataType*>();

    std::cout << "Registro #" << getMetadata()->getNumberOfRecords() << "\n";

//    RecordDataType<char> *record =
//        dynamic_cast<RecordDataType<char>*>(current->getData());
//    const char *option = record->getDataPtr();

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

    _fileSimulation->insert(dataList);
}

void BTRFLocalSimulation::deleteRecord() // TODO
{
}

void BTRFLocalSimulation::searchRecord()
{
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
        folder = folder->getNextPtr();
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
    IN_aryNode<QString> *tmp; // ubicación temporal de la ruta objetivo

    std::cout << "Dirección solicitada: ";
    std::cin >> path;

    qPath = Converter::fromStringToQString(path);

    if (path[0] == '/') { // inicia desde la raíz
        tmp = _fileSystem->searchDir(qPath);

    } else { // desde el directorio donde está el puntero actual
        std::cout << "Entró";
        tmp =
            dynamic_cast<N_aryRecordFileNode<QString>*>(_currentFolder)->
            searchDirInto(new N_aryRecordFileNode<QString>(qPath));
    }

    if (tmp != nullptr) { // sí existe la ruta
        std::cout << "FOLDER: " << tmp->getData().toStdString();
        _currentFolder = dynamic_cast<N_aryRecordFileNode<QString>*>(tmp);
    }
}

void BTRFLocalSimulation::fileHandling()
{
    char option;

    std::cout << "Escriba lo que desea hacer en el archivo:\n"
              " 1. Crear un archivo\n"
              " 2. Insertar registro\n"
              " 3. Borrar registro\n"
              " 4. Modificar registro\n"
              " 5. Buscar registro\n"
              " 6. Crear archivo\n"
              "> ";

    std::cin >> option;

    switch (option) {
    case '1':
        insertRecord();
        break;
    case '2':
        deleteRecord();
        break;
    case '3':
        // TODO agregar método
        break;
    case '4':
        searchRecord();
        break;
    default:
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
        break;
    }
}

BTRecordFileMetadata *BTRFLocalSimulation::createMetadata() const
{
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
              << "(0 para salir):\n"
              << "1. String\n"
              << "2. Char\n"
              << "3. Short\n"
              << "4. Int\n"
              << "5. Double\n"
              << "6. Bool\n"
              << "> ";

    std::cin >> option;

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

    return new BTRecordFileMetadata(fileName, owner, recordStruct);
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
