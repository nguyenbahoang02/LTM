#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class SignIn;
}

class SignIn : public QWidget
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();
    int server_sock;
    QStackedWidget *stackedWidget;

public slots:
    void on_sign_up_clicked();

private slots:
    void on_sign_in_clicked();

private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
