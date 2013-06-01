#include "unittesting.h"

UnitTesting::UnitTesting()
{
    this->_conversor = new Converter();
}

void UnitTesting::Test1_BinaryDecimalConversion()
{
    QVERIFY( _conversor->binaryToDecimal( "00000111" ) == "7" );
    cout << "Conversión de BINARIO a DECIMAL " << "00000111"
         << " a " << "7" << endl;
}

void UnitTesting::Test2_BinaryDecimalConversion()
{
    QVERIFY( _conversor->binaryToDecimal( "101010101010101010101" ) == "1398101" );
    cout << "Conversión de BINARIO a DECIMAL " << "101010101010101010101"
         << " a " << "1398101" << endl;
}

void UnitTesting::Test3_BinaryDecimalConversion()
{
    QVERIFY( _conversor->binaryToDecimal( "11111" ) == "31" );
    cout << "Conversión de BINARIO a DECIMAL " << "11111"
         << " a " << "31" << endl;
}

void UnitTesting::Test4_BinaryDecimalConversion()
{
    QVERIFY( _conversor->binaryToDecimal( "11" ) == "3" );
    cout << "Conversión de BINARIO a DECIMAL " << "111" << " a " << "3" << endl;
}

void UnitTesting::Test5_BinaryDecimalConversion()
{
    QVERIFY( _conversor->binaryToDecimal( "01" ) == "1" );
    cout << "Conversión de BINARIO a DECIMAL " << "01" << " a " << "1" << endl;
}

void UnitTesting::Test1_BinaryStringConversion()
{
    QVERIFY( _conversor->binaryToString( "01001000" ) == "H" );
    cout << "Conversión de BINARIO a STRING "
         << "01001000" << " a " << "H" << endl;
}

void UnitTesting::Test2_BinaryStringConversion()
{
    QVERIFY( _conversor->binaryToString( "0100010001100001" ) == "Da" );
    cout << "Conversión de BINARIO a STRING "
         << "0100010001100001" << " a " << "Da" << endl;
}

void UnitTesting::Test3_BinaryStringConversion()
{
    QVERIFY( _conversor->binaryToString( "0100010001000001" ) == "DA" );
    cout << "Conversión de BINARIO a STRING "
         << "0100010001000001" << " a " << "DA" << endl;
}

void UnitTesting::Test1_VerificaDouble()
{
    QCOMPARE(_conversor->verificaValidezDouble("1.2453"), true);
    cout << "1.2453" << " ES double" << endl;
}

void UnitTesting::Test2_VerificaDouble()
{
    QCOMPARE(_conversor->verificaValidezDouble("12453"), false);
    cout << "12453" << " NO es double" << endl;
}

void UnitTesting::Test3_VerificaDouble()
{
    QCOMPARE(_conversor->verificaValidezDouble("124 53"), false);
    cout << "124 53" << " NO es double" << endl;
}

void UnitTesting::Test4_VerificaDouble()
{
    QCOMPARE(_conversor->verificaValidezDouble("8H8"), false);
    cout << "8H8" << " NO es double" << endl;
}

void UnitTesting::Test5_VerificaDouble()
{
    QCOMPARE(_conversor->verificaValidezDouble("8,8"), true);
    cout << "8,8" << " ES double" << endl;
}

void UnitTesting::Test1_VerificaInt()
{
    QCOMPARE(_conversor->verificaValidezInt("77"), true);
    cout << "77" << " ES int" << endl;
}

void UnitTesting::Test2_VerificaInt()
{
    QCOMPARE(_conversor->verificaValidezInt("7 3"), false);
    cout << "7 3" << " NO es int" << endl;
}

void UnitTesting::Test3_VerificaInt()
{
    QCOMPARE(_conversor->verificaValidezInt("7H9"), false);
    cout << "7H9" << " NO es int" << endl;
}

void UnitTesting::Test4_VerificaInt()
{
    QCOMPARE(_conversor->verificaValidezInt("HOLA"), false);
    cout << "HOLA" << " NO es int" << endl;
}

void UnitTesting::Test5_VerificaInt()
{
    QCOMPARE(_conversor->verificaValidezInt("$"), false);
    cout << "$" << " NO es int" << endl;
}





//QTEST_MAIN( UnitTesting )
