#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "object.h"
#include "object_collection.h"
#include "test.h"


int main(int argc, char *argv[])
{
    test_class();
    test_ms_class();
    cout << "Done\n";


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
