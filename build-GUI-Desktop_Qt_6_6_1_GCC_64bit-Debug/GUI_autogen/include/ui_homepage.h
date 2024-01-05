/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QLabel *label_2;
    QPushButton *find_match_btn;
    QLabel *label_3;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *log_out_btn;
    QPushButton *get_online_players;
    QLineEdit *board_size;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName("HomePage");
        HomePage->resize(800, 600);
        label_2 = new QLabel(HomePage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(610, 60, 131, 21));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        find_match_btn = new QPushButton(HomePage);
        find_match_btn->setObjectName("find_match_btn");
        find_match_btn->setGeometry(QRect(200, 470, 141, 51));
        find_match_btn->setFont(font);
        find_match_btn->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(HomePage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 220, 141, 31));
        QFont font1;
        font1.setPointSize(16);
        label_3->setFont(font1);
        label = new QLabel(HomePage);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 310, 131, 21));
        label->setFont(font);
        scrollArea = new QScrollArea(HomePage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(560, 90, 221, 451));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 449));
        scrollArea->setWidget(scrollAreaWidgetContents);
        log_out_btn = new QPushButton(HomePage);
        log_out_btn->setObjectName("log_out_btn");
        log_out_btn->setGeometry(QRect(30, 50, 88, 25));
        get_online_players = new QPushButton(HomePage);
        get_online_players->setObjectName("get_online_players");
        get_online_players->setGeometry(QRect(630, 550, 88, 25));
        board_size = new QLineEdit(HomePage);
        board_size->setObjectName("board_size");
        board_size->setGeometry(QRect(290, 310, 113, 25));
        board_size->setPlaceholderText(QString::fromUtf8(">2"));

        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QCoreApplication::translate("HomePage", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("HomePage", "Online players", nullptr));
        find_match_btn->setText(QCoreApplication::translate("HomePage", "Find a match", nullptr));
        label_3->setText(QCoreApplication::translate("HomePage", "Game settings", nullptr));
        label->setText(QCoreApplication::translate("HomePage", "Board size AxA", nullptr));
        log_out_btn->setText(QCoreApplication::translate("HomePage", "Log out", nullptr));
        get_online_players->setText(QCoreApplication::translate("HomePage", "Refresh", nullptr));
        board_size->setText(QCoreApplication::translate("HomePage", "16", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
