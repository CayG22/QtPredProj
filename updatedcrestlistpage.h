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
    QScrollArea* scrollArea = nullptr;
    QVBoxLayout* mainLayout = nullptr;
    QWidget* centralWidget = nullptr;
    QWidget* gridWidget = nullptr;
    QGridLayout* gridLayout = nullptr;
    SearchBar* searchBar = nullptr;
    std::vector<QString> crestNames = {};
    std::vector<QString> filteredCrestNames = {};
};

#endif // UPDATEDCRESTLISTPAGE_H
