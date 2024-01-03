#ifndef DATARECEIVER_H
#define DATARECEIVER_H
#include <QObject>
class DataReceiver : public QObject {
    Q_OBJECT

public:
    DataReceiver();

public slots:
    void GetSignal();

signals:
    void login_response_signal(std::string message);
    void signup_response_signal(std::string message);
    void logout_response_signal(std::string message);
    void find_match_response_signal(std::string message);
    void player_list_signal(std::string message);
    void received_challenge_signal(std::string message);
    void declined_challenge_signal(std::string message);
    void created_room_signal(std::string message);
    void accept_find_match_signal(std::string message);
    void create_board_signal(std::string message);
    void update_board_signal(std::string message);
    void winner_signal(std::string message);
    void rematch_signal(std::string message);
    void re_login_response_signal(std::string message);
    void pause_signal(std::string message);
    void pause_accept_signal(std::string message);
    void pause_decline_signal(std::string message);
    void continue_signal(std::string message);
    void continue_accept_signal(std::string message);
    void continue_decline_signal(std::string message);
    void draw_signal(std::string message);
    void draw_accept_signal(std::string message);
    void draw_decline_signal(std::string message);
    void chat_signal(std::string message);
};

#endif // DATARECEIVER_H



