#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    int server_sock;

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
