#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "gamescene.h"

namespace Ui {
class gamewindow;
}

class gamewindow : public QWidget
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = nullptr);
    ~gamewindow();

signals:
    void update_board(std::string);

public slots:
    void handle_create_match_response(std::string);
    void handle_update_board_response(std::string);
    void handle_winner_response(std::string);
    void handle_rematch_response(std::string);
    void handle_pause_response(std::string);
    void handle_pause_decline_response(std::string);

private slots:
    void on_pause_clicked();

private:
    Ui::gamewindow *ui;
    GameScene *scene;
};

#endif // GAMEWINDOW_H
