#include "updatedcrestlistpage.h"
#include "ui_updatedcrestlistpage.h"


UpdatedCrestListPage::UpdatedCrestListPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UpdatedCrestListPage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#1e1e28");
    ui->scrollArea->setWidgetResizable(true);
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->verticalLayoutWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    SearchBar* searchBar = new SearchBar(this);
    connect(searchBar,&SearchBar::searchButtonClicked,this,&UpdatedCrestListPage::search);
    ui->verticalLayout->addWidget(searchBar);

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

void UpdatedCrestListPage::populateGrid(){
    // Remove old items from the grid layout
    QLayout *layout = ui->gridLayout;
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            QWidget *widget = item->widget();
            if (widget) {
                widget->deleteLater();  // Delete the widget to free memory
            }
            delete item;  // Remove the layout item
        }
    }

    //Make sure filteredCrestNames is being used
    const std::vector<QString> &namesToDisplay = filteredCrestNames.empty() ? crestNames:filteredCrestNames;
    qDebug() << namesToDisplay;
    //Grid layout
    int row = 0, col = 0;
    const int columns = 4;
    for(const QString& crestName:namesToDisplay){
        QString image_path = Crest::createImagePath(crestName);
        QPixmap pixmap(image_path);
        QWidget* crestWidget = new QWidget();
        QVBoxLayout* crestLayout = new QVBoxLayout(crestWidget);
        ClickableLabel* crestLabel = new ClickableLabel();
        QLabel* crestLabelName = new QLabel(crestName);

        if(!pixmap.isNull()){
            crestLabel->setPixmap(pixmap.scaled(128,128,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        }else{
            crestLabel->setText(crestName);
        }

        crestLayout->addWidget(crestLabel);
        crestLayout->addWidget(crestLabelName);

        crestWidget->setLayout(crestLayout);
        ui->gridLayout->addWidget(crestWidget,row,col);

        setUpCrestClick(crestLabel,crestName);

        col++;
        if(col>=columns){
            col = 0;
            row++;
        }
    }
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
