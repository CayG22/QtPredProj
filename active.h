#ifndef ACTIVE_H
#define ACTIVE_H
#include<QString>
class Active
{
public:
    Active(const QString& name = "", const QString& description = "")
        : active_name(name),active_description(description){}
    QString active_name;
    QString active_description;

};

#endif // ACTIVE_H
