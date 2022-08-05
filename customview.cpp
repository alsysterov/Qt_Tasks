/* Реализация функции масштабирования сцены с помощью колеса мыши
 */

#include "customview.h"

CustomView::CustomView(QWidget *parent) : QGraphicsView(parent)
{

}

// С использованием колеса мыши:

void CustomView::wheelEvent(QWheelEvent *event)
{

    // Масштабировать относительно положения мыши

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Коэффициент масштабирования

    double scaleFactor = 1.15;

    // При приближении (или вращении колеса вверх)

    if(event->delta() > 0)
    {
        scale(scaleFactor, scaleFactor);
    }

    // При отдалении (или вращении колеса вниз)

    else
    {
        scale(1/scaleFactor, 1/scaleFactor);
    }
}
