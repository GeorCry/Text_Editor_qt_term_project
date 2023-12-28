#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);
    //after closing last window free res of an app and close it
    MainWindow w;//create
    w.show();//show widget
    return a.exec();//running cycle of work
}
