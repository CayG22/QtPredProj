#include "HeroPage.h"
#include "ui_HeroPage.h"

HeroPage::HeroPage(Hero* hero,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HeroPage), currentHero(hero) //Init. with the passed hero
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #7E9CA2");
    QString heroImage = "C:/QT Projects/TestHeroPage/HeroImages/512px-MurdockRender.png";
    QPixmap pixmap(heroImage);
    ui->HeroPic->setPixmap(pixmap);
    ui->HeroName->setText(currentHero->name);
    setUpTable();
    fillTable();
    fillAbilityNameTable();
    fillAbilityValueTable();
    fillAbilityDescription();
}

HeroPage::~HeroPage()
{
    delete ui;

}

void HeroPage::setUpTable(){
    //QStringList to hold all labels for table
    const QStringList rowLabels = {
        "Attack Power",
        "Attack Speed",
        "Basic Attack Time",
        "Actual Attack Time",
        "Attack Range",
        "Cleave",
        "Physical Armor",
        "Magical Armor",
        "Max Health",
        "Max Mana",
        "Health Regeneration",
        "Mana Regeneration",
        "Movement Speed"
    };
    //Loop to populate label rows
    for(int i = 0; i<rowLabels.length(); i++){
        ui->tableWidget->setColumnWidth(i,175);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(rowLabels[i]));
    }

}
void HeroPage::fillTable(){
    //List to hold all of hero's stats
    QList<double> statList = {
        currentHero->m_attack_power,
        currentHero->m_attack_speed,
        currentHero->m_basic_attack_time,
        currentHero->m_actual_attack_time,
        currentHero->m_attack_range,
        currentHero->m_cleave,
        currentHero->m_physical_armor,
        currentHero->m_magical_armor,
        currentHero->m_max_health,
        currentHero->m_max_mana,
        currentHero->m_health_regeneration,
        currentHero->m_mana_regeneration,
        currentHero->m_movement_speed
};
    //Loop to populate data side of table
    for(int i = 0; i< statList.length(); i++){
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(statList[i])));
    }
}
void HeroPage::on_horizontalSlider_valueChanged(int value)
{
    QString formattedText = QString("<b>Level:</b> %1").arg(value);
    ui->SliderLabel->setText(formattedText);
    currentHero->levelUp(value);
    currentHero->levelUpBasic(value);
    ui->BasicSpinBox->setValue(value);
    fillAbilityValueTable();
    fillTable();

}
void HeroPage::fillAbilityNameTable(){
    ui->AlternateName->setText(currentHero->m_alternate.m_name);
    ui->BasicName->setText(currentHero->m_basic.m_name);
    ui->PrimaryName->setText(currentHero->m_primary.m_name);
    ui->SecondaryName->setText(currentHero->m_secondary.m_name);
    ui->UltimateName->setText(currentHero->m_ultimate.m_name);
}
void HeroPage::fillAbilityValueTable(){
    if(currentHero->m_alternate.m_physical_damage == 0){
        ui->AlternateValue->setText(QString::number(currentHero->m_alternate.m_magical_damage));
    }else{
        ui->AlternateValue->setText(QString::number(currentHero->m_alternate.m_physical_damage));
    }

    if(currentHero->m_basic.m_physical_damage == 0){
        ui->BasicValue->setText(QString::number(currentHero->m_basic.m_magical_damage));
    }else{
        ui->BasicValue->setText(QString::number(currentHero->m_basic.m_physical_damage));
    }

    if(currentHero->m_primary.m_physical_damage == 0){
        ui->PrimaryValue->setText(QString::number(currentHero->m_primary.m_magical_damage));
    }else{
        ui->PrimaryValue->setText(QString::number(currentHero->m_primary.m_physical_damage));
    }

    if(currentHero->m_secondary.m_physical_damage == 0){
        ui->SecondaryValue->setText(QString::number(currentHero->m_secondary.m_magical_damage));
    }else{
        ui->SecondaryValue->setText(QString::number(currentHero->m_secondary.m_physical_damage));
    }

    if(currentHero->m_ultimate.m_physical_damage == 0){
        ui->UltimateValue->setText(QString::number(currentHero->m_ultimate.m_magical_damage));
    }else{
        ui->UltimateValue->setText(QString::number(currentHero->m_ultimate.m_physical_damage));
    }
}
void HeroPage::fillAbilityDescription(){}
void HeroPage::on_AlternateSpinBox_valueChanged(int value)
{
    currentHero->levelUpAlternate(value);
    fillAbilityValueTable();
}
void HeroPage::on_PrimarySpinBox_valueChanged(int value)
{
    currentHero->levelUpPrimary(value);
    fillAbilityValueTable();
}
void HeroPage::on_SecondarySpinBox_valueChanged(int value)
{
    currentHero->levelUpSecondary(value);
    fillAbilityValueTable();
}
void HeroPage::on_UltimateSpinBox_valueChanged(int value)
{
    currentHero->levelUpUltimate(value);
    fillAbilityValueTable();
}

