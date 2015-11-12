#include "MyRect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"

#include <QDebug>

void MyRect::spawn()
{
    Bullet* b=new Bullet(2);
    scene()->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();

}


