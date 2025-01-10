#ifndef HEROPAGE_H
#define HEROPAGE_H
#include <QMainWindow>
#include "Hero.h" //Base class for all heroes
namespace Ui {
class HeroPage;
}


class HeroPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HeroPage(Hero* hero,QWidget *parent = nullptr);
    ~HeroPage();
    void setUpTable();
    void fillTable();
    void fillAbilityNameTable();
    void fillAbilityValueTable();
    void fillAbilityDescription();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_AlternateSpinBox_valueChanged(int value);

    void on_PrimarySpinBox_valueChanged(int value);

    void on_SecondarySpinBox_valueChanged(int value);

    void on_UltimateSpinBox_valueChanged(int value);

private:
    Ui::HeroPage *ui;
    Hero* currentHero; //Pointer to the currently selected hero
};
#endif // HEROPAGE_H
