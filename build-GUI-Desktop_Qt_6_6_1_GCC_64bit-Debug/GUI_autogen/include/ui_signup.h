/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QPushButton *sign_in_btn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLineEdit *username_text;
    QLineEdit *password_text;
    QPushButton *sign_up;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(800, 600);
        label = new QLabel(SignUp);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 160, 192, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        layoutWidget = new QWidget(SignUp);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(220, 340, 331, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        QFont font1;
        font1.setPointSize(12);
        label_7->setFont(font1);

        horizontalLayout->addWidget(label_7);

        sign_in_btn = new QPushButton(layoutWidget);
        sign_in_btn->setObjectName("sign_in_btn");

        horizontalLayout->addWidget(sign_in_btn);

        layoutWidget1 = new QWidget(SignUp);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(220, 240, 89, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");
        QFont font2;
        font2.setPointSize(14);
        label_6->setFont(font2);

        verticalLayout_2->addWidget(label_6);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        verticalLayout_2->addWidget(label_5);

        layoutWidget2 = new QWidget(SignUp);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(330, 238, 221, 91));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        username_text = new QLineEdit(layoutWidget2);
        username_text->setObjectName("username_text");

        verticalLayout->addWidget(username_text);

        password_text = new QLineEdit(layoutWidget2);
        password_text->setObjectName("password_text");
        password_text->setClearButtonEnabled(false);

        verticalLayout->addWidget(password_text);

        sign_up = new QPushButton(layoutWidget2);
        sign_up->setObjectName("sign_up");

        verticalLayout->addWidget(sign_up);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Form", nullptr));
        label->setText(QCoreApplication::translate("SignUp", "Welcome to XO C++", nullptr));
        label_7->setText(QCoreApplication::translate("SignUp", "Already have an account ?", nullptr));
        sign_in_btn->setText(QCoreApplication::translate("SignUp", "Sign in", nullptr));
        label_6->setText(QCoreApplication::translate("SignUp", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("SignUp", "Password", nullptr));
        username_text->setPlaceholderText(QCoreApplication::translate("SignUp", "Enter your username ...", nullptr));
#if QT_CONFIG(accessibility)
        password_text->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        password_text->setPlaceholderText(QCoreApplication::translate("SignUp", "Enter your password...", nullptr));
        sign_up->setText(QCoreApplication::translate("SignUp", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
