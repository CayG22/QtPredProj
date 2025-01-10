#include "herolistpage.h"
#include "ui_herolistpage.h"
#include <qlabel.h>
#include <QScrollArea>
#include <QVBoxLayout>
#include "FunctionalClasses.h"
#include "crest.h"
HeroListPage::HeroListPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HeroListPage)
{
    ui->setupUi(this);
    populateGrid();
    std::vector<Crest> crests = Crest::loadCrests("C:/QT Projects/TestHeroPage/PredResourceFiles/Crests.json");
    for(const Crest& crest: crests){
        qDebug() << "Name: " << crest.m_name;
    }
}

HeroListPage::~HeroListPage()
{
    delete ui;
}

void HeroListPage::populateGrid() {

    const QStringList heroList = {
        "Murdock", "Khaimera", "Grux", "Dekker", "Morigesh", "Countess", "Greystone", "Sparrow",
        "Argus", "Yin", "Riktor", "Gideon", "Serath", "Belica", "Aurora", "Skylar", "Kira",
        "Twinblast", "Zinx", "Steel", "Crunch", "Phase", "Shinbi", "Revenant", "Drongo", "Fey",
        "Iggy", "Sevarog", "Terra", "Howitzer", "Kallari", "Feng", "Gadget", "Zarus",
        "Kwang", "Muriel", "Wraith", "Narbash", "Grim", "Rampage"
    };

    const int columns = 5;
    int row = 0, col = 0;

    // Create a QWidget to hold the grid layout
    QWidget *gridWidget = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(gridWidget);

    for (int i = 0; i < heroList.size(); i++){
        //Create a ClickableLabel(FunctionalClasses.h) to create herolabel that is clickable...
        ClickableLabel *heroLabel = new ClickableLabel();
        heroLabel->setText(heroList[i]);
        heroLabel->setAlignment(Qt::AlignCenter);

        // Set size policy to allow the label to expand or shrink
        heroLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        // Load the image
        QString heroName = heroList[i];
        QString imagePath = "C:/QT Projects/TestHeroPage/HeroListImages/" + heroName + ".jpg";
        QPixmap heroPixmap(imagePath);

        if (!heroPixmap.isNull()) {
            heroLabel->setPixmap(heroPixmap.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            heroLabel->setText(heroName);
        }

        gridLayout->addWidget(heroLabel, row, col);

        //Connect the clicked signal to a slot
        connect(heroLabel, &ClickableLabel::clicked, this, [this, heroName]() {
            qDebug() << "Hero clicked:" << heroName;
            //Uses HeroFactory to create the hero object that we want the displayed page to be
            Hero* selectedHero = HeroFactory::createHero(heroName);
            //Check if mainWindow is already created
            if(!heroPage){
                heroPage = new HeroPage(selectedHero,this); //Pass in the selected hero to the heroPage class
            }else{
                delete heroPage; //Clean up the old hero page
                heroPage = new HeroPage(selectedHero,this);
            }
            //Show the main window if it is not visible
            if(!heroPage->isVisible()){
                heroPage->show();
            }
        });
        col++;
        if (col >= columns) {
            col = 0;
            row++;
        }
    }

    // Create the scroll area and set it to be resizable
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(gridWidget);  // Set the gridWidget as the scrollable content
    scrollArea->setWidgetResizable(true);  // Allow the scroll area content to resize dynamically

    // Create a layout for the central widget of the main window
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(scrollArea);  // Add scroll area to the layout

    // Set the layout of the central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);  // Set the central widget of the main window
}
