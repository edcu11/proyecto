#ifndef MYRECT_H
#define MYRECT_H
#include <qobject.h>
#include <arreglo.h>

#include <QGraphicsRectItem>

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
    void spawn(int t,,Arreglo* a);
};

#endif // MYRECT_H
