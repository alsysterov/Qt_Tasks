/*#include "mysquarea.h"

MySquareA::MySquareA()
{
    Pressed = false;
    Moved = false;
}

QRectF MySquareA::boundingRect(int i, int j)
{
    return QRectF(30 * i,30 * j,30,30);
}

void MySquareA::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rec = boundingRect();
    QBrush greenBrush(Qt::green);
    QLine line1, line2, line3;

    if(Pressed)
    {
        line1 << QPoint(points1[0]) << QPoint(points1[1]);
        painter->drawLine(line1);
        line2 << QPoint(points2[0]) << QPoint(points2[1]);
        painter->drawLine(line2);
        line3 << QPoint(points1[2]) << QPoint(points2[2]);
        painter->drawLine(line3);
    }
}

void MySquareA::paintEvent(QPaintEvent *event)
{
    QPainter mytext(this);
    mytext.setFont(QFont("Times", 8));
    mytext.drawText(QPoint(), "A");
}

void MySquareA::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    Moved = false;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MySquareA::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    Moved = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void MySquareA::mouseMoveEvent(QGraphicsSceneMouseEvent **event)
{
    Pressed = false;
    Moved = true;
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void MySquareA::makeSquare(int i, int j)
{
    QTextItem LetterA;
}

QGraphicsItem *MySquareA::itemCollidesWith(QGraphicsItem *item)
{

}*/
