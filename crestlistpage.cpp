#include<QLabel>
#include<QScrollArea>
#include<QVBoxLayout>
#include<QLabel.h>

#include "crestlistpage.h"
#include "ui_crestlistpage.h"
#include "crest.h"
#include "FunctionalClasses.h"
CrestListPage::CrestListPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CrestListPage)
{
    ui->setupUi(this);
    populateGrid();
}

CrestListPage::~CrestListPage()
{
    delete ui;
}

void CrestListPage::populateGrid(){
    std::vector<Crest> crests = Crest::loadCrests(":/JSON/PredResourceFiles/Crests.json");

    int row = 0, col = 0;
    const int columns = 5;

    //Create a new QWidget to hold the grid layout
    QWidget* gridWidget = new QWidget();
    QGridLayout* gridLayout = new QGridLayout(gridWidget);

    for(Crest& crest: crests){
        //Create a clickable label
        ClickableLabel *crestLabel = new ClickableLabel();
        crestLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        //TODO:: ADD NAMES TO ALSO DISPLAY ON THIS PAGE

        //Load image
        QString image_path = Crest::createImagePath(crest.m_name);
        qDebug() << image_path;
        QPixmap pixmap(image_path);
        if(!pixmap.isNull()){
        crestLabel->setPixmap(pixmap.scaled(128,128, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        gridLayout->addWidget(crestLabel,row,col);
        }else{
            crestLabel->setText(crest.m_name);
            gridLayout->addWidget(crestLabel,row,col);
        }

        //Connect call will go here...
        connect(crestLabel, &ClickableLabel::clicked, this, [this,crest](){
            //qDebug() << "Crest clicked: " << crest.m_name;
            if(!crestPage){
                crestPage = new CrestPage(crest,this);
            }else{
                delete crestPage; // Clean up old crest page
                crestPage = new CrestPage(crest,this);
            }
            if(!crestPage->isVisible()){
                crestPage->show();
            }
        });

        col++;
        if(col>=columns){
            col = 0;
            row++;
        }
    }

    //Create a scroll area and set it to be resizable
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(gridWidget);
    scrollArea->setWidgetResizable(true);

    //Create a layout for the central widget of the main window
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);

    //Set the layout of the central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}


