#ifndef ABILITY_H
#define ABILITY_H
#include <QString>
class Ability
{
public:
    QString m_name = "";
    QString m_description = "";
    int m_level = 1;
    double m_physical_damage = 0.0;
    double m_magical_damage = 0.0;
    double m_physical_scale = 0.0;
    double m_magical_scale = 0.0;
    double m_heal = 0.0;

    /*Methods WILL EVENTUALLY MAKE GETTER METHODS TO GET NAME,DAMAGE, ETC.*/
    Ability();
    void setName(const QString& name){m_name = name;}
    void setPhysicalDamage(double damage){m_physical_damage = damage;}
    void setMagicaldamage(double damage){m_magical_damage = damage;}
    void setPhysicalScale(double scale){m_physical_scale = scale;}
    void setMagicalScale(double scale){m_magical_scale = scale;}
    void setHeal(double heal){m_heal = heal;}
    void setLevel(int level){m_level = level;}
    void setDescription(const QString& description){m_description = description;}
};

#endif // ABILITY_H
