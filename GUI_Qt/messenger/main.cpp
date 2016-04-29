//This is the main driver file for the Qt Messenger GUI
//It instantiates an object of the Messenger class,
//and then displays the GUI

#include "messenger.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Instantiate messenger object, which is the GUI window
    Messenger w;

    //run the messenger Gui
    w.show();

    return a.exec();
}
