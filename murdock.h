#ifndef MURDOCK_H
#define MURDOCK_H
#include<QApplication>
#include "hero.h"
class Murdock: public Hero
{    
public:
    Murdock();
    void setStats() override;
    void levelUp(int level) override;
    void setBasic() override;
    void setPassive() override;
    void setAlternate() override;
    void setPrimary() override;
    void setSecondary() override;
    void setUltimate() override;
    void levelUpBasic(int level) override;
    void levelUpAlternate(int level) override;
    void levelUpPrimary(int level) override;
    void levelUpSecondary(int level) override;
    void levelUpUltimate(int level) override;
    /*
    void levelUp(int level);
    QString name = "Murdock";
    double m_attack_power = 62.0;
    double m_attack_speed = .125;
    double m_basic_attack_time = 1.4;
    double m_actual_attack_time = 1.12;
    double m_attack_range = 1300;
    double m_cleave = 0.0;
    double m_physical_armor = 22.0;
    double m_magical_armor = 25.0;
    double m_max_health = 745.0;
    double m_max_mana = 310.0;
    double m_health_regeneration = 1.5;
    double m_mana_regeneration = 1.4;
    double m_movement_speed = 645.0;
*/
};

#endif // MURDOCK_H
