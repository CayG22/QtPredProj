#include "crest.h"
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QDebug>

Crest Crest::loadFullCrestData(const QString& crestName) {
    QFile file(":/JSON/PredResourceFiles/Crests.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file.";
        return Crest("", "");
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray crestArray = doc.array();

    for (const QJsonValue& value : crestArray) {
        QJsonObject obj = value.toObject();
        if (obj["name"].toString() == crestName) {
            //Extract active object sepearately
            QJsonObject activeObj = obj["active"].toObject();
            Active active(activeObj["active_name"].toString(),activeObj["active_description"].toString(),activeObj["active_cooldown"].toInt());
            return Crest(
                obj["name"].toString(),
                obj["image_path"].toString(),
                obj["physical_power"].toInt(),
                obj["magical_power"].toInt(),
                obj["physical_penetration"].toInt(),
                obj["critical_chance"].toDouble(),
                obj["attack_speed"].toDouble(),
                obj["lifesteal"].toDouble(),
                obj["omnivmap"].toDouble(),
                obj["physical_armor"].toDouble(),
                obj["magical_armor"].toDouble(),
                obj["tenacity"].toDouble(),
                obj["max_health"].toDouble(),
                obj["max_mana"].toDouble(),
                obj["health_regeneration"].toDouble(),
                obj["mana_regeneration"].toDouble(),
                obj["ability_haste"].toDouble(),
                obj["movement_speed"].toDouble(),
                active
                );
        }
    }

    return Crest("", ""); // Return an empty Crest if not found
}
QString Crest::createImagePath(const QString& name){
    QString non_const_copy = name;
    non_const_copy.remove(' ');
    QString img_path = ":/images/CrestImages/" + non_const_copy + ".jpg";
    return img_path;
}

