#ifndef CRESTLISTPAGE_H
#define CRESTLISTPAGE_H

#include <QMainWindow>

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
private:
    Ui::CrestListPage *ui;
};

#endif // CRESTLISTPAGE_H
