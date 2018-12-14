#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QSvgGenerator>
#include <QFileDialog>
#include <QPainter>
#include "graph.h"
#include <cmath>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(/*QWidget *parent = 0, */Graph *g = 0);
    ~MainWindow();
    void paintGraph(Graph &g);
private:
    QRect getRect(int i, int n);
    QPoint getPoint(int i, int n);
    QGraphicsScene *scene;
    QString path;
    int h = 400;
    int w = 400;
    void boruvka(Graph* g);
};

#endif // MAINWINDOW_H
