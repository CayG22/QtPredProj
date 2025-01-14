#include<QLabel>
#include<QScrollArea>
#include<QVBoxLayout>
#include<QLabel.h>
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>

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
    const int columns = 5;

    QWidget* gridWidget = new QWidget();
    QGridLayout* gridLayout = new QGridLayout(gridWidget);

    for (const QString& crestName : crestNames) {
        // Create a clickable label
        ClickableLabel* crestLabel = new ClickableLabel();
        crestLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        // Load image
        QString image_path = Crest::createImagePath(crestName);
        qDebug() << image_path;
        QPixmap pixmap(image_path);
        if (!pixmap.isNull()) {
            crestLabel->setPixmap(pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            gridLayout->addWidget(crestLabel, row, col);
        } else {
            crestLabel->setText(crestName);
            gridLayout->addWidget(crestLabel, row, col);
        }

        // Connect label click to action
        connect(crestLabel, &ClickableLabel::clicked, this, [this, crestName]() {
            if (!crestPage) {
                crestPage = new CrestPage(Crest(crestName), this);
            } else {
                delete crestPage; // Clean up old crest page
                crestPage = new CrestPage(Crest(crestName), this);
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


