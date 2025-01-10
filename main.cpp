#include "HeroPage.h"
#include "herolistpage.h"
#include "crestlistpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    HeroListPage w;
    w.show();
    return a.exec();
}
