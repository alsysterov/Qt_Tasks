/*#ifndef CUSTOM_H
#define CUSTOM_H

#include <QGraphicsItem>
#include <QPainter>

class Custom : public QGraphicsItem
{
public:
    Custom();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
private:
    QPoint points1[17];
    QPoint points2[17];
};

#endif // CUSTOM_H*/
