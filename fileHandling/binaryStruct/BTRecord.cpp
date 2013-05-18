/*******************************************************************************
 * File: BTRecord.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de BTRecord.h
 * Reference:
 ******************************************************************************/

#include "BTRecord.h"
#include "util/Converter.h"

BTRecord::BTRecord()
{
    this->_parentPtr = 0;
    this->_leftChildPtr = 0;
    this->_rightChildPtr = 0;
}

DLL<IRecordDataType *> *BTRecord::getDataListPtr() const
{
    return _dataListPtr;
}

void BTRecord:: setDataList(DLL<IRecordDataType *> *pDataListPtr)
{
    _dataListPtr = pDataListPtr;
}


unsigned short BTRecord::getParentPtr() const
{
    return _parentPtr;
}

void BTRecord::setParentPtr(unsigned short pParentPtr)
{
    _parentPtr = pParentPtr;
}

unsigned short BTRecord::getLeftChildPtr() const
{
    return _leftChildPtr;
}

void BTRecord::setLeftChildPtr(unsigned short pLeftChildPtr)
{
    _leftChildPtr = pLeftChildPtr;
}

unsigned short BTRecord::getRightChildPtr() const
{
    return _rightChildPtr;
}

void BTRecord::setRightChildPtr(unsigned short pRightChildPtr)
{
    _rightChildPtr = pRightChildPtr;
}

void BTRecord::printRecord() const
{
    cout <<  "Parent" << setw(15) << "LeftChild" << setw(15) << "RightChild" << endl;
    cout << setw(3) << _parentPtr << setw(15) << _leftChildPtr << setw(15) <<
             _rightChildPtr << setw(15);
    DLLNode<IRecordDataType*> *tmp = _dataListPtr->getHeadPtr();
    RecordDataType<std::string> *data;
    while( tmp != nullptr ){
        data = dynamic_cast<RecordDataType<std::string>*>(tmp->getData());
        cout << *data->getDataPtr() << setw(15);
        tmp = tmp->getNextPtr();
    }
    cout << "\n";
}

/**
 * @brief BTRecord::castRecordToBinary
 * @return finalBinaryRecord, registro casteado a binario
 */
std::string BTRecord::castRecordToBinary()
{
    std::string finalBinaryRecord;  // concatenacion del registro
    Converter *conversion = new Converter();
    finalBinaryRecord += conversion->decimalToBinary( std::to_string( _parentPtr ) );
    finalBinaryRecord += conversion->decimalToBinary( std::to_string( _leftChildPtr ) );
    finalBinaryRecord += conversion->decimalToBinary( std::to_string( _rightChildPtr ) );
    DLLNode<IRecordDataType*> *tmp = _dataListPtr->getHeadPtr();
    RecordDataType<std::string> *data;
    while( tmp != nullptr ){
        data = dynamic_cast<RecordDataType<std::string>*>(tmp->getData());
        std::string str( *data->getDataPtr() ); // Convert from std::string 2 Qstring
        QString qstrData(str.c_str()); // donde qstr es el QString

        if ( !verificaValidezInt( qstrData ) ){ // cadena no de numeros
            finalBinaryRecord += conversion->stringToBinary( *data->getDataPtr() );
        }
        else{   // son solo numeros
            finalBinaryRecord += conversion->decimalToBinary( *data->getDataPtr() );
        }
        tmp = tmp->getNextPtr();
    }
    cout << "El registro en BINARIO es: " << "\n" << finalBinaryRecord << endl;
    return finalBinaryRecord;
}

bool BTRecord::verificaValidezInt( QString pDato ){
    bool charValido;
    int validaIntroduceNumeros;
    for(int i = 0; i < 9; i++){
        //validacion de que solo se introducen numeros(convierten qstring a int)
        validaIntroduceNumeros = pDato.toInt(&charValido);
        if(charValido == false){    //existe un caracter que no es número
            return false;
        }//fin del if interno
        else{
            return true;
        }//fin if
    }//fin del for
}
