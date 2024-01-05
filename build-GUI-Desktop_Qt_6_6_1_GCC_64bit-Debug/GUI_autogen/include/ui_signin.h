/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignIn
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QPushButton *sign_up;
    QLabel *label;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *username_text;
    QLineEdit *password_text;
    QPushButton *sign_in;

    void setupUi(QWidget *SignIn)
    {
        if (SignIn->objectName().isEmpty())
            SignIn->setObjectName("SignIn");
        SignIn->resize(800, 600);
        layoutWidget = new QWidget(SignIn);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(220, 330, 331, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        QFont font;
        font.setPointSize(12);
        label_7->setFont(font);

        horizontalLayout->addWidget(label_7);

        sign_up = new QPushButton(layoutWidget);
        sign_up->setObjectName("sign_up");

        horizontalLayout->addWidget(sign_up);

        label = new QLabel(SignIn);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 160, 192, 31));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        layoutWidget_2 = new QWidget(SignIn);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(220, 230, 89, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName("label_6");
        QFont font2;
        font2.setPointSize(14);
        label_6->setFont(font2);

        verticalLayout_2->addWidget(label_6);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        verticalLayout_2->addWidget(label_5);

        layoutWidget_3 = new QWidget(SignIn);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(330, 228, 221, 91));
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        username_text = new QLineEdit(layoutWidget_3);
        username_text->setObjectName("username_text");

        verticalLayout->addWidget(username_text);

        password_text = new QLineEdit(layoutWidget_3);
        password_text->setObjectName("password_text");
        password_text->setEchoMode(QLineEdit::Password);
        password_text->setClearButtonEnabled(false);

        verticalLayout->addWidget(password_text);

        sign_in = new QPushButton(layoutWidget_3);
        sign_in->setObjectName("sign_in");

        verticalLayout->addWidget(sign_in);


        retranslateUi(SignIn);

        QMetaObject::connectSlotsByName(SignIn);
    } // setupUi

    void retranslateUi(QWidget *SignIn)
    {
        SignIn->setWindowTitle(QCoreApplication::translate("SignIn", "Form", nullptr));
        label_7->setText(QCoreApplication::translate("SignIn", "Create an account ?", nullptr));
        sign_up->setText(QCoreApplication::translate("SignIn", "Sign up", nullptr));
        label->setText(QCoreApplication::translate("SignIn", "Welcome to XO C++", nullptr));
        label_6->setText(QCoreApplication::translate("SignIn", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("SignIn", "Password", nullptr));
        username_text->setPlaceholderText(QCoreApplication::translate("SignIn", "Enter your username ...", nullptr));
#if QT_CONFIG(accessibility)
        password_text->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        password_text->setPlaceholderText(QCoreApplication::translate("SignIn", "Enter your password...", nullptr));
        sign_in->setText(QCoreApplication::translate("SignIn", "Sign in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignIn: public Ui_SignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
