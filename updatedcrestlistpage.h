#ifndef UPDATEDCRESTLISTPAGE_H
#define UPDATEDCRESTLISTPAGE_H

#include <QMainWindow>
#include<QScrollArea>
#include<QLabel>
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>

#include "crestpage.h"
#include "FunctionalClasses.h"
namespace Ui {
class UpdatedCrestListPage;
}

class UpdatedCrestListPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpdatedCrestListPage(QWidget *parent = nullptr);
    ~UpdatedCrestListPage();
    void populateGrid();
    void search(const QString& searchText);
    void loadJSON();
    void setUpCrestClick(ClickableLabel* crestLabel,const QString& crestName);

private:
    Ui::UpdatedCrestListPage *ui;
    CrestPage* crestPage = nullptr;
    ClickableLabel* crestLabel = nullptr;
    SearchBar* searchBar;
    QScrollArea* scrollArea;
    QVBoxLayout* mainLayout;
    std::vector<QString> crestNames = {};
    std::vector<QString> filteredCrestNames = {};
};

#endif // UPDATEDCRESTLISTPAGE_H
