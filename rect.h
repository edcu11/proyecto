#ifndef RECT_H
#define RECT_H
#include <qobject.h>
#include <QGraphicsRectItem>

class rect: public QObject, public QGraphicsRectItem
{
     Q_OBJECT
public:
    rect(int arreglo[20][10]);
    int (*arreglo)[10];
    void keyPressEvent(QKeyEvent * event);
    void spawn(int t);
};

#endif // RECT_H
