#ifndef CUSTOMRECT_H
#define CUSTOMRECT_H

#include <QGraphicsRectItem>
#include <QDebug>
class CustomRect : public QGraphicsRectItem{
public :
    int x;
    int y;
    int value;
    qreal tile_size;
    explicit CustomRect();
    explicit CustomRect(int _x,int _y, qreal start_x,qreal start_y, qreal _tile_size){
        x = _x;
        y = _y;
        value = 0;
        tile_size = _tile_size;
        setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
    }
    void send_update_board_signal();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CUSTOMRECT_H
