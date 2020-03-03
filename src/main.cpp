#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include "wloutput_interface.h"

const QString VERSION = "1.0.1";


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setApplicationName("wloutput-interface");
    // app version
    QCoreApplication::setApplicationVersion(VERSION); // app version

    wloutput_interface object;

    if(!object.InitDBus())
    {
        qDebug() << "InitDBus failed!";
        exit(-1);
    }

    object.StartWork();

    qDebug() << "wloutput-interface";

    return a.exec();
}
