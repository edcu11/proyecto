#ifndef MYRECT_H
#define MYRECT_H
#include <qobject.h>

#include <QGraphicsRectItem>

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn(int t);
};

#endif // MYRECT_H
