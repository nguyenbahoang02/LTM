#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "gamescene.h"
#include <QVBoxLayout>

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
    void handle_pause_accept_response(std::string);
    void handle_pause_decline_response(std::string);
    void handle_continue_response(std::string);
    void handle_continue_accept_response(std::string);
    void handle_continue_decline_response(std::string);
    void handle_draw_response(std::string);
    void handle_draw_accept_response(std::string);
    void handle_draw_decline_response(std::string);
    void handle_chat_response(std::string);

private slots:
    void on_pause_clicked();

    void on_draw_clicked();

    void on_return_2_clicked();

    void on_send_clicked();

    void on_message_returnPressed();

private:
    Ui::gamewindow *ui;
    GameScene *scene;
    QVBoxLayout *vbox;
};

#endif // GAMEWINDOW_H
