// EXTRAÍDO DE http://www.qtforum.org/article/26097/qimage-qbytearray-qstring.html
// Convierte una imagen a BMP  y pone su expresión hexadecimal en un archivo

#include <QCoreApplication>
#include <QImage>
#include <QFile>
#include <QByteArray>
#include <QBuffer>

int ex2()
{
    QImage image("example/ex2/1.jpg");
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf, "BMP");

    QByteArray compressed = qCompress(ba, 1);
    QByteArray hexed = compressed.toHex();

    // save to a file
    QString str(hexed);
    QFile f("example/ex2/test.hex");
    if (f.exists())
        f.remove();
    if (f.open(QFile::WriteOnly)) {
        f.write(str.toLatin1()); // holds only 0..f nothing special.
    } else
        qDebug("failed to open file \"test.hex\"");
    f.close();

    if (f.open(QFile::ReadOnly)) {
        QByteArray read = f.readAll();
        f.close();
        QString rStr = QString::fromLatin1(read.data(), read.size());
        if (rStr != str)
            qDebug("Writed and read two different hexed strings.");

        QByteArray readCompressed = QByteArray::fromHex(rStr.toAscii());
        if (readCompressed != compressed)
            qDebug("bytes before hexing and dehexing _is_ different.");
        QByteArray readDecompressed = qUncompress(readCompressed);

        if (readDecompressed != ba)
            qDebug("bytes before and after compressions are different.");

        QImage readImg;
        readImg.loadFromData(readDecompressed);

        if (readImg.isNull())
            qDebug("The image is null. Something failed.");
        readImg.save("example/ex2/test.bmp");
    } else
        qDebug("failed to open test.hex file for reading");
    return 0;
}

