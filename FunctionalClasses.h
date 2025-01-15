#ifndef FUNCTIONALCLASSES_H
#define FUNCTIONALCLASSES_H
#include<QLabel>
#include<QMouseEvent>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include "Hero.h"
#include "Murdock.h"

/*Handles Left mouse clicks for the hero labels*/
class ClickableLabel: public QLabel{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr) : QLabel(parent){
        setAlignment(Qt::AlignCenter);
        setStyleSheet("background-color:#191923;border-radius:8px");
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
    void enterEvent(QEnterEvent* event)override{
        setStyleSheet("background-color:#2A2A35;border-radius:8px");
        QLabel::enterEvent(event);
    }
    void leaveEvent(QEvent* event) override{
        setStyleSheet("background-color:#191923;border-radius:8px");
        QLabel::leaveEvent(event);
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

/*Helper function for making a search bar     WILL IMPLEMENT AT A LATER DATE TOO HARD RN*/
class SearchBar : public QWidget {
    Q_OBJECT

public:
    explicit SearchBar(QWidget *parent = nullptr) {
        // Initialize search bar and button
        lineEdit = new QLineEdit(this);
        searchButton = new QPushButton("Search", this);

        // Set placeholder text
        lineEdit->setPlaceholderText("Type to search...");

        // Create layout
        QHBoxLayout *layout = new QHBoxLayout(this);
        layout->addWidget(lineEdit);
        layout->addWidget(searchButton);
        layout->setContentsMargins(0, 0, 0, 0);
        setLayout(layout);

        // Connect signals
        connect(lineEdit, &QLineEdit::textChanged, this, &SearchBar::searchTextChanged);
        connect(searchButton, &QPushButton::clicked, this, [this]() {
            emit searchButtonClicked(lineEdit->text());
        });
    }

    QString getSearchText() const { return lineEdit->text(); }

signals:
    void searchTextChanged(const QString &text);
    void searchButtonClicked(const QString &text);

private:
    QLineEdit *lineEdit;
    QPushButton *searchButton;
};


#endif // FUNCTIONALCLASSES_H
