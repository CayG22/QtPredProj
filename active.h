#ifndef ACTIVE_H
#define ACTIVE_H
#include<QString>
class Active
{
public:
    Active(const QString& name = "", const QString& description = "", const int cooldown = 0)
        : active_name(name),active_description(description),active_cooldown(cooldown){}
    QString active_name;
    QString active_description;
    int active_cooldown;
};

#endif // ACTIVE_H
