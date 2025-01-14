#include<QLabel>
#include<QScrollArea>
#include<QVBoxLayout>
#include<QLabel.h>
#include<qdebug.h>
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>

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
    //Path to JSON file
    const QString filePath = ":/JSON/PredResourceFiles/Items.json";

    //Vector to hold crest names
    std::vector<QString> itemNames;

    //Open and parse the JSON file
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qWarning() << "Could not open file: " << filePath;
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if(!doc.isArray()){
        qWarning() << "Invalid JSON format: expected an array.";
        return;
    }
    QJsonArray itemArray = doc.array();
    for(const QJsonValue& value : itemArray){
        if(value.isObject()){
            QJsonObject itemObject = value.toObject();
            if(itemObject.contains("name") && itemObject["name"].isString()){
                itemNames.push_back(itemObject["name"].toString());
            }else{
                qWarning() << "Crest object missing 'name' filed or it's not a string";
            }
        }else{
            qWarning() << "Invalid crest entry format, expected an object";
        }
    }
    int row = 0, col = 0;
    const int columns = 5;

    //Create a new QWidget to hold the grid layout
    QWidget* gridWidget = new QWidget();
    QGridLayout* gridLayout = new QGridLayout(gridWidget);

    for (const QString &itemName : itemNames) {
        // Create a QWidget to hold both image and name
        QWidget *itemWidget = new QWidget();
        QVBoxLayout *verticalLayout = new QVBoxLayout(itemWidget);

        // Create a clickable label for the image
        ClickableLabel *itemLabel = new ClickableLabel();
        itemLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        // Load image
        QString image_path = Item::createImagePath(itemName);
        qDebug() << image_path;
        QPixmap pixmap(image_path);
        if (!pixmap.isNull()) {
            itemLabel->setPixmap(pixmap.scaled(128, 128, Qt::KeepAspectRatio,
                                                Qt::SmoothTransformation));
        } else {
            itemLabel->setText(itemName); // If no image, set the name as text
        }

        // Add the clickable label for the image to the vertical layout
        verticalLayout->addWidget(itemLabel);

        // Create label for the crest name
        QLabel *nameLabel = new QLabel(itemName);
        nameLabel->setAlignment(Qt::AlignCenter);
        verticalLayout->addWidget(nameLabel);

        // Add the widget with image and name to the grid
        gridLayout->addWidget(itemWidget, row, col);

        //Will add connect call here

        col++;
        if (col >= columns) {
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
