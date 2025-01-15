#ifndef CRESTLISTPAGE_H
#define CRESTLISTPAGE_H

#include <QMainWindow>
#include "crestpage.h"
namespace Ui {
class CrestListPage;
}

class CrestListPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit CrestListPage(QWidget *parent = nullptr);
    ~CrestListPage();
    void populateGrid();
    void setUpSearchBar();
private:
    Ui::CrestListPage *ui;
    CrestPage* crestPage = nullptr;
};

#endif // CRESTLISTPAGE_H

