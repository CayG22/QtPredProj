#ifndef ITEM_H
#define ITEM_H
#include<QString>
class Item
{
public:
    Item(
        const QString& name = "",
        const QString& image_path = "",
        int physical_power = 0,
        int magical_power = 0,
        int physical_penetration = 0,
        double critical_chance = 0.0,
        double attack_speed = 0.0,
        double lifesteal = 0.0,
        double omnivmap = 0.0,
        double physical_armor = 0.0,
        double magical_armor = 0.0,
        double tenacity = 0.0,
        double max_health = 0.0,
        double max_mana = 0.0,
        double health_regeneration = 0.0,
        double mana_regeneration = 0.0,
        double ability_haste = 0.0,
        double movement_speed = 0.0
    )
    : m_name(name),
        m_image_path(image_path),
        m_physical_power(physical_power),
        m_magical_power(magical_power),
        m_physical_penetration(physical_penetration),
        m_critical_chance(critical_chance),
        m_attack_speed(attack_speed),
        m_lifesteal(lifesteal),
        m_omnivmap(omnivmap),
        m_physical_armor(physical_armor),
        m_magical_armor(magical_armor),
        m_tenacity(tenacity),
        m_max_health(max_health),
        m_max_mana(max_mana),
        m_health_regeneration(health_regeneration),
        m_mana_regeneration(mana_regeneration),
        m_ability_haste(ability_haste),
        m_movement_speed(movement_speed)
    {
    }
    QString m_name;
    QString m_image_path;
    int m_physical_power;
    int m_magical_power;
    int m_physical_penetration;
    double m_critical_chance;
    double m_attack_speed;
    double m_lifesteal;
    double m_omnivmap;
    double m_physical_armor;
    double m_magical_armor;
    double m_tenacity;
    double m_max_health;
    double m_max_mana;
    double m_health_regeneration;
    double m_mana_regeneration;
    double m_ability_haste;
    double m_movement_speed;

    static std::vector<Item> loadItems(const QString& filePath);
};

#endif // ITEM_H
