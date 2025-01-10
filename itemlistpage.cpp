#include "itemlistpage.h"
#include "ui_itemlistpage.h"
#include "item.h"
itemlistpage::itemlistpage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::itemlistpage)
{
    ui->setupUi(this);
    populateGrid();
}

itemlistpage::~itemlistpage()
{
    delete ui;
}

void itemlistpage::populateGrid(){
    std::vector<Item> items = Item::loadItems("C:/Users/Cayden/Documents/GitHub/QtPredProj/PredResourceFiles/Items.json");
    for(const Item& item:items){
        qDebug() << item.m_name;
    }
}
