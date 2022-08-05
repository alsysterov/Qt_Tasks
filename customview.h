/* Класс для объявления возможности масштабирования сцены
 */

#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QtWidgets>

class CustomView : public QGraphicsView
{
public:
    CustomView(QWidget* parent = 0);
protected:

    // Объявление функции использования колеса мыши

    virtual void wheelEvent(QWheelEvent *event);
};

#endif // CUSTOMVIEW_H
