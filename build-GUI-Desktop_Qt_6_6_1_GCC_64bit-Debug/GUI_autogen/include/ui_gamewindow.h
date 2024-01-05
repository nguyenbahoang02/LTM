/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamewindow
{
public:
    QLabel *label;
    QLabel *player_turn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *message;
    QPushButton *send;
    QPushButton *pause;
    QGraphicsView *graphicsView;
    QPushButton *draw;
    QPushButton *return_2;

    void setupUi(QWidget *gamewindow)
    {
        if (gamewindow->objectName().isEmpty())
            gamewindow->setObjectName("gamewindow");
        gamewindow->resize(800, 600);
        label = new QLabel(gamewindow);
        label->setObjectName("label");
        label->setGeometry(QRect(650, 50, 71, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        player_turn = new QLabel(gamewindow);
        player_turn->setObjectName("player_turn");
        player_turn->setGeometry(QRect(220, 40, 171, 21));
        player_turn->setFont(font);
        scrollArea = new QScrollArea(gamewindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(570, 80, 221, 421));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 419));
        scrollArea->setWidget(scrollAreaWidgetContents);
        message = new QLineEdit(gamewindow);
        message->setObjectName("message");
        message->setGeometry(QRect(570, 510, 171, 25));
        send = new QPushButton(gamewindow);
        send->setObjectName("send");
        send->setGeometry(QRect(750, 510, 41, 25));
        pause = new QPushButton(gamewindow);
        pause->setObjectName("pause");
        pause->setGeometry(QRect(140, 530, 88, 25));
        graphicsView = new QGraphicsView(gamewindow);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(60, 70, 450, 450));
        draw = new QPushButton(gamewindow);
        draw->setObjectName("draw");
        draw->setGeometry(QRect(360, 530, 88, 25));
        draw->setCursor(QCursor(Qt::ArrowCursor));
        return_2 = new QPushButton(gamewindow);
        return_2->setObjectName("return_2");
        return_2->setGeometry(QRect(10, 10, 88, 25));

        retranslateUi(gamewindow);

        QMetaObject::connectSlotsByName(gamewindow);
    } // setupUi

    void retranslateUi(QWidget *gamewindow)
    {
        gamewindow->setWindowTitle(QCoreApplication::translate("gamewindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("gamewindow", "Chat log", nullptr));
        player_turn->setText(QCoreApplication::translate("gamewindow", "Player turn", nullptr));
        message->setText(QString());
        send->setText(QCoreApplication::translate("gamewindow", "Send", nullptr));
        pause->setText(QCoreApplication::translate("gamewindow", "Pause", nullptr));
        draw->setText(QCoreApplication::translate("gamewindow", "Draw", nullptr));
        return_2->setText(QCoreApplication::translate("gamewindow", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamewindow: public Ui_gamewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
