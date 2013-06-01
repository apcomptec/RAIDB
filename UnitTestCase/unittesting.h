#ifndef UNITTESTING_H
#define UNITTESTING_H

#include <iostream>
#include <QtTest/QtTest>
#include <QtTest/QTest>
#include <QDebug>
#include <util/Converter.h>

class UnitTesting : public QObject{
    Q_OBJECT

private:
    Converter *_conversor;

public:
       UnitTesting();

private slots:
       void Test1_BinaryDecimalConversion();
       void Test2_BinaryDecimalConversion();
       void Test3_BinaryDecimalConversion();
       void Test4_BinaryDecimalConversion();
       void Test5_BinaryDecimalConversion();

       void Test1_BinaryStringConversion();
       void Test2_BinaryStringConversion();
       void Test3_BinaryStringConversion();

       void Test1_VerificaDouble();
       void Test2_VerificaDouble();
       void Test3_VerificaDouble();
       void Test4_VerificaDouble();
       void Test5_VerificaDouble();

       void Test1_VerificaInt();
       void Test2_VerificaInt();
       void Test3_VerificaInt();
       void Test4_VerificaInt();
       void Test5_VerificaInt();


};



#endif // UNITTESTING_H

