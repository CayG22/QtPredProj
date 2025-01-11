#include<QLabel>
#include<QScrollArea>
#include<QVBoxLayout>
#include<QLabel.h>
#include<qdebug.h>
#include "itemlistpage.h"
#include "ui_itemlistpage.h"
#include "item.h"
#include "FunctionalClasses.h"
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
    std::vector<Item> items = Item::loadItems(":/JSON/PredResourceFiles/Items.json");

    int row = 0, col = 0;
    const int columns = 5;

    //Create a new QWidget to hold the grid layout
    QWidget* gridWidget = new QWidget();
    QGridLayout* gridLayout = new QGridLayout(gridWidget);

    for(const Item& item: items){
        //Create a clickable label
        ClickableLabel* itemLabel = new ClickableLabel();
        itemLabel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        //TODO: ADD NAMES TO ALSO DISPLAY ON THIS PAGE

        //Load image
        QString image_path = Item::createImagePath(item.m_name);
        qDebug() << image_path;
        QPixmap pixmap(image_path);
        if(!pixmap.isNull()){
        itemLabel->setPixmap(pixmap.scaled(128,128,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        gridLayout->addWidget(itemLabel,row,col);
        }else{
            itemLabel->setText(item.m_name);
            gridLayout->addWidget(itemLabel,row,col);
        }
        col++;
        if(col>=columns){
            col = 0;
            row++;
        }
    }

    //Create a scroll area and set it to be resizable
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(gridWidget);
    scrollArea->setWidgetResizable(true);

    //Create a layout for the central widget of the main window
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(scrollArea);

    //Set the layout of the central widget
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
