/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QPushButton *pushButton;
    QListView *listPlayers;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName("home");
        home->resize(800, 600);
        pushButton = new QPushButton(home);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 470, 141, 51));
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        listPlayers = new QListView(home);
        listPlayers->setObjectName("listPlayers");
        listPlayers->setGeometry(QRect(585, 90, 191, 471));
        label = new QLabel(home);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 310, 91, 21));
        label->setFont(font);
        lineEdit = new QLineEdit(home);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(260, 310, 271, 25));
        label_2 = new QLabel(home);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(620, 60, 131, 21));
        label_2->setFont(font);
        label_3 = new QLabel(home);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 220, 141, 21));
        QFont font1;
        font1.setPointSize(16);
        label_3->setFont(font1);
        pushButton_2 = new QPushButton(home);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 380, 88, 25));
        QFont font2;
        font2.setPointSize(13);
        pushButton_2->setFont(font2);

        retranslateUi(home);

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QWidget *home)
    {
        home->setWindowTitle(QCoreApplication::translate("home", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("home", "Find a match", nullptr));
        label->setText(QCoreApplication::translate("home", "Board size", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("home", "Enter board size (>2)", nullptr));
        label_2->setText(QCoreApplication::translate("home", "Online players", nullptr));
        label_3->setText(QCoreApplication::translate("home", "Game settings", nullptr));
        pushButton_2->setText(QCoreApplication::translate("home", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
