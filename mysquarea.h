/*#ifndef MYSQUAREA_H
#define MYSQUAREA_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QTextItem>
#include <QPaintEvent>

class MySquareA : public QGraphicsItem
{
public:
    MySquareA();

   // QRectF boundingRect(int i, int j);
   // QTextItem LetterA;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void paintEvent(QPaintEvent *event);
    bool Pressed;
    bool Moved;
protected:
   virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
   virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
   virtual void mouseMoveEvent(QGraphicsSceneMouseEvent **event);
private:
   // QPoint points1[3];
   // QPoint points2[3];
    void makeSquare(int i, int j);
    QGraphicsItem * itemCollidesWith(QGraphicsItem * item);

};

#endif*/ // MYSQUAREA_H
