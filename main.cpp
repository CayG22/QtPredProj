#include "HeroPage.h"
#include "herolistpage.h"
#include "crestlistpage.h"
#include "itemlistpage.h"
#include <QApplication>
#include<QDebug>
#include<QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    itemlistpage w;
    w.show();
    qDebug() << "Current Path:" << QDir::currentPath();
    return a.exec();
}
