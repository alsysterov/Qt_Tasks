#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <custom.h>

// Максимальный размер массива для хранения квадратов

const int MAX_ARRAY = 200;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    // Объявление функций нажатия на кнопки

    void on_GenerateButton_clicked();
    void on_PathShower_clicked();
    //void wheelEvent(QWheelEvent* event);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:

    // Объявление объектов, используемых в главном окне

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle[MAX_ARRAY][MAX_ARRAY];

protected:
    //void paintEvent(QPaintEvent*) override;
};

#endif // MAINWINDOW_H
