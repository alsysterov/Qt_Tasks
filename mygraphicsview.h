/*#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = 0);
    ~MyGraphicsView();
    void wheelEvent(QWheelEvent* event);

private:
    //QGraphicsScene *scene;
    //QGraphicsItemGroup *group_1;
    //QGraphicsItemGroup *group_2;

    qreal h11 = 1.0;
    qreal h12 = 0;
    qreal h21 = 1.0;
    qreal h22 = 0;

    //void resizeEvent(QResizeEvent *event);

    //void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};

#endif // MYGRAPHICSVIEW_H*/
