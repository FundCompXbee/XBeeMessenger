#include "messenger.h"
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Messenger w;

    w.show();


    return a.exec();
}
