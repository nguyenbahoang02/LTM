#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();
    int server_sock;

private slots:
    void on_save_btn_clicked();

private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
