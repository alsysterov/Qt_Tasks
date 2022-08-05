/* Главное окно приложения, реализующее почти все
 * необходимые функции
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bfs.h"
#include "mygraphicsview.h"
#include <QMessageBox>
#include <QDebug>
#include <QtGui>
#include <cstdlib>
#include <QObject>
#include <QTextStream>
#include <QGraphicsView>
#include <QMouseEvent>

using namespace std;

// Объявление глобальных переменных

// Максимально допустимый размер массива (в одном направлении),
// задаётся в зависимости от максимального числа квадратов в длину или в ширину

int const MAX_ARRAY_SIZE = 200;

// Максимальное количество квадратов (элементов массива)

int const MAX_ARRAY_DIM = MAX_ARRAY_SIZE * MAX_ARRAY_SIZE;

// Главный массив, через который проходят вычисления кратчайшего пути
// от заданной до заданной точек

int gridArray[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

// Переменные для временного хранения точки массива, находящейся
// слева и сверху рассматриваемой соответственно

int leftgrid,upgrid;

// Объект класса поиска пути Graph

Graph Field;

// Конструктор главного окна, задание сцены в GraphicsView

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->grid->setScene(scene);
}

// Деструктор главного окна

MainWindow::~MainWindow()
{
    delete ui;
}

// Событие нажатия кнопки "Генерировать"

void MainWindow::on_GenerateButton_clicked()
{
    // Принятие ввода ширины и высоты поля пользователем и конвертация
    // Формата строки (string) в целочисленный формат (integer)

    int width = ui->lineEdit_width->text().toInt();
    int height = ui->lineEdit_height->text().toInt();

    // Контроль ввода данных, допустимый размер поля был выбран мною
    // от 2 (меньший размер не будет иметь смысл) до 200 (при размере более 200
    // приходится ждать генерации поля несколько дольше), при неверном вводе
    // данных появляется окно, сообщающее об ошибке и блокирующее ввод от его
    // принятия.

    if(width < 2 || height < 2 || width > 200 || height > 200)
        QMessageBox::critical(this,"Ошибка","Неподдерживаемый размер поля. Пожалуйста, введите размер поля от 2 до 200 включительно.",
                              QMessageBox::Ok);
    else
    {

        // Инициализация временных переменных (особо важна в случае глобальных переменных)

        leftgrid = -2;
        upgrid = -2;

        // Инициализация главного массива

        for (int k = 0; k < MAX_ARRAY_SIZE; k++)
        {
            for (int p = 0; p < MAX_ARRAY_SIZE; p++)
            {
                gridArray[k][p] = -1;
            }
        }

        // Чистка объекта для его дальнейшего корректного использования

        Field.ClearMap();

        // Переменная для генератора псевдослучайных чисел

        int rnd;

        // Чистка сцены перед каждой дальнейшей её прорисовкой

        scene->QGraphicsScene::clear();

        // Объект красной диагонально-полосной заливки

        QBrush redDiagBrush(Qt::red,Qt::BDiagPattern);

        // Объект чёрного контура

        QPen blackPen(Qt::black);

        // Прорисовка поля с заданными размерами

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // Генератор псевдослучайных чисел от 0 до 2 включительно

                rnd = rand() % 3;

                // При шансе 1 к 3 рисуется занятый квадрат

                if (rnd == 0)
                {
                   // Добавление занятого квадрата с размерами 30 на 30 на сцену и его запись
                   // в соответствующий объект

                   rectangle[i][j] = scene->addRect(30 * j,30 * i,30,30, blackPen,redDiagBrush);

                   // Присвоение ему значения -1

                   gridArray[i][j] = -1;
                }

                // При шансе 2 к 3 рисуется пустой квадрат

                else
                {
                   rectangle[i][j] = scene->addRect(30 * j,30 * i,30,30, blackPen);

                   // Присвоение значения порядкового номера свободному квадрату для проведения
                   // дальнейших вычислений с ним

                   gridArray[i][j] = (width * i) + j;
                }
            }
        }

        // Создание графа из свободных квадратов (точнее их порядковых значений)

        for (int l = 0; l < height; l++)
        {
            for (int m = 0; m < width; m++)
            {
                // Проверка на отсутствие квадратов со значением -1 (препятствий)

                if (m != 0 && gridArray[l][m-1] != -1 && gridArray[l][m] != -1)
                {
                    // Создание ребра графа между двумя горизонтально-соседними квадратами

                    leftgrid = gridArray[l][m-1];
                    Field.AddEdge(leftgrid, gridArray[l][m]);
                }
                if (l != 0 && gridArray[l - 1][m] != -1 && gridArray[l][m] != -1)
                {
                    // Создание ребра графа между двумя вертикально-соседними квадратами

                    upgrid = gridArray[l - 1][m];
                    Field.AddEdge(upgrid, gridArray[l][m]);
                }
            }
        }
        update();
    }
}

// Событие нажатия кнопки "Показать путь" (временное решение до введения графической прорисовки)

void MainWindow::on_PathShower_clicked()
{
    // Принятие ввода порядкового номера начального и конечного квадратов пользователем

    int start = ui->lineEdit_input_start->text().toInt();
    int finish = ui->lineEdit_input_finish->text().toInt();

    // Создание своего списка для временного хранения пути

    list<int> MyPath;

    // Запись найденного пути (либо значений -1,-1 при его отсутствии) в свой список

    MyPath = Field.BFS(start, finish, MAX_ARRAY_DIM);

    // Объект для вывода информации на экран

    QTextStream out (stdout);
    out << "The shortest path is: " << "\n";

    // Вывод содержимого списка на экран

    while (!MyPath.empty())
    {
        out << MyPath.front() << endl;
        MyPath.pop_front();
    }
}
