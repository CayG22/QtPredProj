#ifndef HEROLISTPAGE_H
#define HEROLISTPAGE_H

#include <QMainWindow>
#include "HeroPage.h"

namespace Ui {
class HeroListPage;
}

class HeroListPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HeroListPage(QWidget *parent = nullptr);
    ~HeroListPage();
    void populateGrid();

private:
    Ui::HeroListPage *ui;
    HeroPage *heroPage = nullptr; //Create a instance of heroPage when class is instantiated

};

#endif // HEROLISTPAGE_H
