//This app is currently being made for Version 1.2
//DONT CHANGE ANYTHING IN THE RESOURCES FILE, IT TAKES FOREVER TO BUILD...
#include "HeroPage.h"
#include "herolistpage.h"
#include "crestlistpage.h"
#include "itemlistpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    CrestListPage w;
    //HeroListPage w;
    //itemlistpage w;
    w.show();
    return a.exec();
}
