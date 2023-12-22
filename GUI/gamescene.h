#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "customrect.h"

class GameScene : public QGraphicsScene
{
public:
    int size;
    GameScene(int _size){
        size = _size;
        qreal tile_size = 450.0/size;
        for(int i = 0; i< size; i++){
            for(int j = 0; j<size; j++){
                qreal start_x = i*tile_size;
                qreal start_y = j*tile_size;
                tile[i+1][j+1] =  new CustomRect(i+1,j+1,start_x,start_y,tile_size);
                tile[i+1][j+1]->setRect(start_x,start_y,tile_size,tile_size);
                tile[i+1][j+1]->setBrush(Qt::white);
                tile[i+1][j+1]->setPen(QPen(Qt::black,2));
                this->addItem(tile[i+1][j+1]);
            }
        }
    };
    CustomRect *tile[100][100];
public slots:
    void update_board(std::string message);
};

#endif // GAMESCENE_H
