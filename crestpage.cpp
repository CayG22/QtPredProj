#include "crestpage.h"
#include "ui_crestpage.h"

CrestPage::CrestPage(Crest crest, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CrestPage), currentCrest(crest) //Init. with the passed in crest
{
    ui->setupUi(this);
    QString image_path = ":/images/CrestImages/" + currentCrest.m_name + ".jpg";
    qDebug() << image_path;
    QPixmap pixmap(image_path);
    ui->CrestImage->setPixmap(pixmap);

}

CrestPage::~CrestPage()
{
    delete ui;
}
