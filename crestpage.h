#ifndef CRESTPAGE_H
#define CRESTPAGE_H

#include <QMainWindow>
#include "crest.h"
namespace Ui {
class CrestPage;
}

class CrestPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit CrestPage(Crest crest, QWidget *parent = nullptr);
    ~CrestPage();
    void setUpTable();
    void fillTable();

private:
    Ui::CrestPage *ui;

    //Passing by value here since PBR was not getting entire obj's data... Does not matter since
    //We will not be modifying any of the objects traits here...
    Crest currentCrest;
};

#endif // CRESTPAGE_H
