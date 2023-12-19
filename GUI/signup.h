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

public slots:
    void handle_response(std::string message);

private slots:
    void on_sign_in_btn_clicked();
    void on_sign_up_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
