#include "updatedcrestlistpage.h"
#include "ui_updatedcrestlistpage.h"


UpdatedCrestListPage::UpdatedCrestListPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UpdatedCrestListPage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#1e1e28");

    searchBar = new SearchBar(this);

    connect(searchBar, &SearchBar::searchButtonClicked, this, &UpdatedCrestListPage::search);

    // Create main layout and set it only once
    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(searchBar); // Add search bar at the top

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    mainLayout->addWidget(scrollArea); // Add scroll area below search bar

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Load data and populate grid
    loadJSON();
    populateGrid();
}

UpdatedCrestListPage::~UpdatedCrestListPage()
{
    delete ui;
}

void UpdatedCrestListPage::search(const QString& searchText){
    filteredCrestNames.clear();
    for(const QString& name:crestNames){
        if(name.contains(searchText,Qt::CaseInsensitive)){
            filteredCrestNames.push_back(name);
        }
    }
    populateGrid();
}

void UpdatedCrestListPage::populateGrid() {
    const std::vector<QString>& namesToDisplay = filteredCrestNames.empty() ? crestNames : filteredCrestNames;

    // Create a new grid widget and layout
    QWidget* gridWidget = new QWidget();
    QGridLayout* gridLayout = new QGridLayout(gridWidget);

    int row = 0, col = 0;
    const int columns = 4;
    for (const QString& crestName : namesToDisplay) {
        QString image_path = Crest::createImagePath(crestName);
        QPixmap pixmap(image_path);

        QWidget* crestWidget = new QWidget();
        QVBoxLayout* crestLayout = new QVBoxLayout(crestWidget);
        ClickableLabel* crestLabel = new ClickableLabel();
        QLabel* crestLabelName = new QLabel(crestName);

        if (!pixmap.isNull()) {
            crestLabel->setPixmap(pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            crestLabel->setText(crestName);
        }

        crestLayout->addWidget(crestLabel);
        crestLayout->addWidget(crestLabelName);
        crestWidget->setLayout(crestLayout);

        gridLayout->addWidget(crestWidget, row, col);

        setUpCrestClick(crestLabel, crestName);

        col++;
        if (col >= columns) {
            col = 0;
            row++;
        }
    }

    // Update the scroll area's widget
    scrollArea->setWidget(gridWidget);
}

void UpdatedCrestListPage::loadJSON(){
    // Path to the JSON file
    const QString filePath = ":/JSON/PredResourceFiles/Crests.json";

    // Open and parse the JSON file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file:" << filePath;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (!doc.isArray()) {
        qWarning() << "Invalid JSON format: expected an array.";
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

}

void UpdatedCrestListPage::setUpCrestClick(ClickableLabel* crestLabel,const QString& crestName){
    connect(crestLabel,&ClickableLabel::clicked,this,[this,crestName](){
        Crest crestObj;
        if(!crestPage){
            crestObj = Crest::loadFullCrestData(crestName);
            crestPage = new CrestPage(crestObj,this);
        }else{
            delete crestPage;
            crestObj = Crest::loadFullCrestData(crestName);
            crestPage = new CrestPage(crestObj,this);
        }
        if(!crestPage->isVisible()){
            crestPage->show();
        }
    });
}
