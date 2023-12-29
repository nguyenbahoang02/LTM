#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
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
    void add_O(int x, int y, qreal tile_size){
        qreal start_x = (x-1)*tile_size;
        qreal start_y = (y-1)*tile_size;
        QGraphicsTextItem * circle = new QGraphicsTextItem;
        circle->setPos(start_x+tile_size/6,start_y+tile_size/14);
        circle->setPlainText("O");
        circle->setDefaultTextColor(Qt::blue);

        this->addItem(circle);
    }
    void add_X(int x, int y, qreal tile_size){
        qreal start_x = (x-1)*tile_size;
        qreal start_y = (y-1)*tile_size;
        QGraphicsTextItem * cross = new QGraphicsTextItem;
        cross->setPos(start_x+tile_size/6,start_y+tile_size/14);
        cross->setPlainText("X");
        cross->setDefaultTextColor(Qt::red);

        this->addItem(cross);
    }
public slots:
    void update_board(std::string message);
};

#endif // GAMESCENE_H
