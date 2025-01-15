#include "crestlistpage.h"
#include "ui_crestlistpage.h"
#include "FunctionalClasses.h"
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include <qscrollarea.h>

CrestListPage::CrestListPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CrestListPage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#1e1e28");
    //setUpSearchBar();
    populateGrid();
}

CrestListPage::~CrestListPage()
{
    delete ui;
}

void CrestListPage::populateGrid() {

    // Path to the JSON file
    const QString filePath = ":/JSON/PredResourceFiles/Crests.json";

    // Vector to hold crest names
    std::vector<QString> crestNames;

    // Open and parse the JSON file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file:" << filePath;
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (!doc.isArray()) {
        qWarning() << "Invalid JSON format: expected an array.";
        return;
    }

    QJsonArray crestArray = doc.array();
    for (const QJsonValue& value : crestArray) {
        if (value.isObject()) {
            QJsonObject crestObject = value.toObject();
            if (crestObject.contains("name") && crestObject["name"].isString()) {
                crestNames.push_back(crestObject["name"].toString());
            } else {
                qWarning() << "Crest object missing 'name' field or it's not a string.";
            }
        } else {
            qWarning() << "Invalid crest entry format, expected an object.";
        }
    }

    // Grid setup
    int row = 0, col = 0;
    const int columns = 4;

    QWidget* gridWidget = new QWidget();
    QGridLayout* gridLayout = new QGridLayout(gridWidget);
    for (const QString &crestName : crestNames) {
        // Create a QWidget to hold both image and name
        QWidget *crestWidget = new QWidget();
        QVBoxLayout *verticalLayout = new QVBoxLayout(crestWidget);

        // Create a clickable label for the image
        ClickableLabel *crestLabel = new ClickableLabel();
        crestLabel->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);

        // Load image
        QString image_path = Crest::createImagePath(crestName);
        qDebug() << image_path;
        QPixmap pixmap(image_path);
        if (!pixmap.isNull()) {
            crestLabel->setPixmap(pixmap.scaled(128, 128, Qt::KeepAspectRatio,
                                                Qt::SmoothTransformation));
        } else {
            crestLabel->setText(crestName); // If no image, set the name as text
        }
        // Add the clickable label for the image to the vertical layout
        verticalLayout->addWidget(crestLabel);

        // Create label for the crest name
        QLabel *nameLabel = new QLabel(crestName);
        nameLabel->setAlignment(Qt::AlignCenter);
        verticalLayout->addWidget(nameLabel);
        nameLabel->setStyleSheet("font-family:sans-serif;color:#a0a0a0;font-size:20px");
        // Add the widget with image and name to the grid
        gridLayout->addWidget(crestWidget, row, col);

        // Connect label click to action
        connect(crestLabel, &ClickableLabel::clicked, this, [this, crestName]() {
            Crest crestObj;
            if (!crestPage) {
                crestObj = Crest::loadFullCrestData(crestName);
                crestPage = new CrestPage(crestObj, this);
            } else {
                delete crestPage; // Clean up old crest page
                crestObj = Crest::loadFullCrestData(crestName);
                crestPage = new CrestPage(crestObj, this);
            }
            if (!crestPage->isVisible()) {
                crestPage->show();
            }
        });

        col++;
        if (col >= columns) {
            col = 0;
            row++;
        }
    }

    // Scrollable area setup
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(gridWidget);
    scrollArea->setWidgetResizable(true);
    // Layout setup
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}


