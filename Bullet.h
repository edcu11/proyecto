#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>

class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet(int s);
    int p_y,p_x,tam,tam_g;
    void keyPressEvent(QKeyEvent * event);
    void spawn(int t);
public slots:
    void move();
};

#endif // BULLET_H
