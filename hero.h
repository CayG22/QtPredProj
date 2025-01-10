#ifndef HERO_H
#define HERO_H
#include<QString>
#include "ability.h"
class Hero
{
public:
    QString name = "";
    /*Stats*/
    double m_attack_power = 0.0;
    double m_attack_speed = 0.0;
    double m_basic_attack_time = 0.0;
    double m_actual_attack_time = 0.0;
    double   m_attack_range = 0;
    double m_cleave = 0.0;
    double m_physical_armor = 0.0;
    double m_magical_armor = 0.0;
    double m_max_health = 0.0;
    double m_max_mana = 0.0;
    double m_health_regeneration = 0.0;
    double m_mana_regeneration = 0.0;
    double m_movement_speed = 0.0;
    /*Abilities*/
    Ability m_basic;
    Ability m_passive;
    Ability m_alternate;
    Ability m_primary;
    Ability m_secondary;
    Ability m_ultimate;

    Hero();
    virtual void setStats() = 0;
    virtual void levelUp(int level) = 0;
    virtual void setBasic() = 0;
    virtual void setPassive() = 0;
    virtual void setAlternate() = 0;
    virtual void setPrimary() = 0;
    virtual void setSecondary() = 0;
    virtual void setUltimate() = 0;
    virtual void levelUpBasic(int level) = 0;
    virtual void levelUpAlternate(int level) = 0;
    virtual void levelUpPrimary(int level) = 0;
    virtual void levelUpSecondary(int level) = 0;
    virtual void levelUpUltimate(int level) = 0;
};

#endif // HERO_H
