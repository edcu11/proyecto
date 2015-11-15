#ifndef RECT_H
#define RECT_H
#include <qobject.h>
#include <QGraphicsRectItem>
#include <Bullet.h>

class rect: public QObject, public QGraphicsRectItem
{
     Q_OBJECT
public:
    rect(int arreglo[20][10], QList<Bullet*> *lista);
    int (*arreglo)[10];
    QList<Bullet*>* lista;
    void keyPressEvent(QKeyEvent * event);
    void spawn(int t);
};

#endif // RECT_H
