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
    void search(const QString& searchText);
    void loadJSON();
private:
    Ui::CrestListPage *ui;
    CrestPage* crestPage = nullptr;
    std::vector<QString> crestNames = {};
    std::vector<QString> filteredCrestNames;

};

#endif // CRESTLISTPAGE_H

