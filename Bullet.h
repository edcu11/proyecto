#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>

class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();
    int p_y,p_x;
    void keyPressEvent(QKeyEvent * event);
    void spawn();
public slots:
    void move();
};

#endif // BULLET_H
