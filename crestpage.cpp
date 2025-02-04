#include "crestpage.h"
#include "ui_crestpage.h"

CrestPage::CrestPage(Crest crest, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CrestPage), currentCrest(crest) //Init. with the passed in crest
{
    ui->setupUi(this);

    currentCrest.m_name.remove(" ");
    QString image_path = ":/images/CrestImages/" + currentCrest.m_name + ".jpg";
    qDebug() << image_path;
    QPixmap pixmap(image_path);

    ui->CrestImage->setPixmap(pixmap);
    ui->CrestImage->setAlignment(Qt::AlignCenter);
    ui->CrestName->setText(currentCrest.m_name);
    ui->CrestName->setAlignment(Qt::AlignCenter);
    ui->CrestName->setStyleSheet("QLabel{color:#6763A0;font-size:30px}");
    //ui->CrestImage->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setStyleSheet("background-color:#191923;font-family:sans-serif");

    fillTable();
}

CrestPage::~CrestPage()
{
    delete ui;
}

void CrestPage::fillTable(){
    ui->BuffTable->setColumnCount(2);
    ui->BuffTable->setHorizontalHeaderLabels({"Buff","Value"});
    QList<QPair<QString,QVariant>> buffs = {
        {"Physical Power", currentCrest.m_physical_power},
        {"Magical Power", currentCrest.m_magical_power},
        {"Physical Penetration", currentCrest.m_physical_penetration},
        {"Critical Chance", currentCrest.m_critical_chance},
        {"Attack Speed", currentCrest.m_attack_speed},
        {"Lifesteal", currentCrest.m_lifesteal},
        {"Omnivamp", currentCrest.m_omnivmap},
        {"Physical Armor", currentCrest.m_physical_armor},
        {"Magical Armor", currentCrest.m_magical_armor},
        {"Tenacity", currentCrest.m_tenacity},
        {"Max Health", currentCrest.m_max_health},
        {"Max Mana", currentCrest.m_max_mana},
        {"Health Regeneration", currentCrest.m_health_regeneration},
        {"Ability Haste", currentCrest.m_ability_haste},
        {"Movement Speed", currentCrest.m_movement_speed}
    };

    int validRowCount = 0;
    for(const auto& buff:buffs){
        if(!buff.second.isNull() && buff.second.toDouble() != 0){
            validRowCount++;
        }
    }
    ui->BuffTable->setRowCount(validRowCount);

    int row = 0;
    for(const auto& buff : buffs){
        if(buff.second.isNull() || buff.second.toDouble() == 0){
            continue; //Skip if empty or zero value buffs
        }
        //Allow for table to blend in with background
        ui->BuffTable->setStyleSheet("QTableWidget {font-size:14px;background-color:transparent; border:none}");
        //Setting items
        ui->BuffTable->setItem(row,1,new QTableWidgetItem(buff.first));
        ui->BuffTable->setItem(row,0,new QTableWidgetItem("+" + buff.second.toString()));

        //Editing row attributes
        QTableWidgetItem *item = ui->BuffTable->item(row,0);
        if(!item){
            item = new QTableWidgetItem();
            ui->BuffTable->setItem(row,0,item);
        }
        QTableWidgetItem *text = ui->BuffTable->item(row,1);
        if(!item){
            text = new QTableWidgetItem();
            ui->BuffTable->setItem(row,1,text);
        }
        item->setForeground(QColor("#69A656"));
        text->setForeground(QColor("#868186"));

        row++;
    }

    ui->BuffTable->resizeColumnsToContents();
    ui->BuffTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->BuffTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    displayActiveInfo();
}
void CrestPage::displayActiveInfo(){
    QString activeName = currentCrest.m_active.active_name;
    QString activeDesc = currentCrest.m_active.active_description;
    QString active_cooldown = QString::number(currentCrest.m_active.active_cooldown);

    ui->ActiveName->setText(activeName);
    ui->ActiveName->setStyleSheet("color:#AF69AF;font-size:14px");

    ui->ActiveCooldown->setText("CD: " + active_cooldown + "s");
    ui->ActiveCooldown->setStyleSheet("color:#AF8769;font-size:14px");

    ui->ActiveDesc->setTextFormat(Qt::RichText);
    ui->ActiveDesc->setText(formatText(activeDesc));
    ui->ActiveDesc->setStyleSheet("color:#A0A0A0;font-size:14px");
}
QString CrestPage::formatText(QString& inputText){
    QStringList splitText = inputText.split('-');
    QStringList modifiedTextList;
    QStringList modifiedTextList2;
    QRegularExpression Pregex("\\(\\+(\\d+%\\sP)\\)");
    QRegularExpression Hregex("\\(\\+(\\d+%\\sH)\\)");
    //Gonna have to make this way more efficient and dynamic... Works for now
    for(const QString& word:splitText){
        QRegularExpressionMatch Pmatch = Pregex.match(word);
        QString PmatchedText = Pmatch.captured(0);
        QString modifiedText = word;


        modifiedText.replace(Pmatch.capturedStart(0),PmatchedText.length(),"<span style = 'color:#af6969'> " + PmatchedText + " </span>");
        modifiedTextList.append(modifiedText);
    }
    for(const QString& word:modifiedTextList){
        QRegularExpressionMatch Hmatch = Hregex.match(word);
        QString HmatchedText = Hmatch.captured(0);
        QString modifiedText = word;
        modifiedText.replace(Hmatch.capturedStart(0),HmatchedText.length(),"<span style = 'color:#69af69'> " + HmatchedText + " </span>");
        modifiedTextList2.append(modifiedText);
    }
    modifiedTextList2.removeAll("");
    QString finalString = modifiedTextList2.join("<br/>");
    qDebug() << finalString;
    return finalString;
}
