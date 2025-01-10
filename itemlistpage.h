#ifndef ITEMLISTPAGE_H
#define ITEMLISTPAGE_H

#include <QMainWindow>

namespace Ui {
class itemlistpage;
}

class itemlistpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit itemlistpage(QWidget *parent = nullptr);
    ~itemlistpage();
    void populateGrid();
private:
    Ui::itemlistpage *ui;
};

#endif // ITEMLISTPAGE_H
