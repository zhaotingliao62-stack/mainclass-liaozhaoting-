#include "mainclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainClass window;
    window.show();
    return application.exec();
}

