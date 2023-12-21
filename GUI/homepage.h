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
    bool finding_match = false;
    void change_find_btn_state();

public slots:
    void handle_logout_response(std::string message);
    void handle_find_match_response(std::string message);
    void handle_player_list_response(std::string message);
    void handle_received_challenge(std::string message);
    void handle_declined_challenge_response(std::string message);
    void handle_created_room_response(std::string message);
    void handle_accept_find_match_response(std::string message);

private slots:
    void on_log_out_btn_clicked();
    void on_find_match_btn_clicked();
    void on_get_online_players_clicked();
    void send_challenge(std::string username);

public:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
