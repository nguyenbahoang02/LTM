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

private slots:
    void on_log_out_btn_clicked();

    void on_find_match_btn_clicked();

public:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
