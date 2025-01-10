#include "crest.h"
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QDebug>

std::vector<Crest> Crest::loadCrests(const QString& filePath){
    std::vector<Crest> crests;
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning() << "Could not open file: " << filePath;
        return crests;
    }
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray crestArray = doc.array();
    for(const QJsonValue& value: crestArray){
        QJsonObject obj = value.toObject();
        Crest crest(
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
            obj["movement_speed"].toDouble()
            );
        crests.push_back(crest);
    }
    return crests;
}