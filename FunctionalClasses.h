#ifndef FUNCTIONALCLASSES_H
#define FUNCTIONALCLASSES_H
#include<QLabel>
#include<QMouseEvent>
#include "Hero.h"
#include "Murdock.h"

/*Handles Left mouse clicks for the hero labels*/
class ClickableLabel: public QLabel{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr) : QLabel(parent){
        setAlignment(Qt::AlignCenter);
        setStyleSheet("background-color:transparent");
    }

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override{
        if(event->button() == Qt::LeftButton){
            emit clicked();
        }
        QLabel::mousePressEvent(event);
    }
};

/*Helper function to store all hero information*/
class HeroFactory{
public:
    static Hero* createHero(const QString& heroName){ //Takes whatever hero it is given, and return that hero's object
        if(heroName == "Murdock") return new Murdock();
        //Add more heroes
        return nullptr;
    }
};




#endif // FUNCTIONALCLASSES_H
