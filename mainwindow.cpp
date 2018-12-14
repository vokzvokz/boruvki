#include "mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(/*QWidget *parent, */Graph *g)
    //: QMainWindow(parent)
{
    //qDebug()<<"I'm here";
    scene = new QGraphicsScene();
    QGraphicsView* graphicsView = new QGraphicsView(scene, this);
    this->setGeometry(50,50,h,w);
    graphicsView->setGeometry(0,0,h,w);
    scene->setSceneRect(0,0,h,w);

        paintGraph(*g);

        QString newPath = "test.svg";

        path = newPath;
        QSvgGenerator generator;        // Создаём объект генератора файла
        generator.setFileName(path);    // Устанавливаем путь к файлу, куда будет сохраняться векторная графика
        generator.setSize(QSize(scene->width(), scene->height()));  // Устанавливаем размеры рабочей области документа в миллиметрах
        generator.setViewBox(QRect(0, 0, scene->width(), scene->height())); // Устанавливаем рабочую область в координатах
        generator.setTitle(trUtf8("SVG Example"));                          // Титульное название документа
        generator.setDescription(trUtf8("File created by SVG Example"));    // Описание документа

            // С помощью класса QPainter
            QPainter painter;
            painter.begin(&generator);  // Устанавливаем устройство/объект в котором будем производить отрисовку
            scene->render(&painter);    // Отрисовываем содержимое сцены с помощью painter в целевое устройство/объект
            painter.end();
            //scene->show();
}

QRect MainWindow::getRect(int i, int n){
    pair<double, double> center(h/2.0, w/2.0);
    double l = min(h, w)/3.0;
    return QRect((center.first+l*sin((i+1)*2*M_PI/n)), center.second+l*cos((i+1)*2*M_PI/n), 10, 10);
}

QPoint MainWindow::getPoint(int i, int n){
    return getRect(i, n).center();
}

void MainWindow::paintGraph(Graph &g){
    /*for(int i = 0; i<g.V; i++){
        for(int j =i; j<g.V; j++){
            if(g.matrix[i][j]>0){
                QGraphicsLineItem* edge = new QGraphicsLineItem(getPoint(i, g.V).x(), getPoint(i, g.V).y(),
                                                                getPoint(j, g.V).x(), getPoint(j, g.V).y());
                edge->setPen(QPen(QBrush(Qt::black),2));
                scene->addItem(edge);
                //qDebug()<<i<<"  "<<j;
            }
        }
    }*/
    for(int i = 0; i<g.E; i++){
        QGraphicsLineItem* edge = new QGraphicsLineItem(getPoint(g.edge[i].dest, g.V).x(),
                                                        getPoint(g.edge[i].dest, g.V).y(),
                                                        getPoint(g.edge[i].src, g.V).x(),
                                                        getPoint(g.edge[i].src, g.V).y());
        edge->setPen(QPen(QBrush(Qt::black),2));
        scene->addItem(edge);
    }
    for(int i = 0; i<g.V; i++){
        QGraphicsEllipseItem* vertex = new QGraphicsEllipseItem();
        vertex->setRect(getRect(i, g.V));
        vertex->setBrush(QBrush(Qt::red));
        vertex->setPen(QPen(QBrush(Qt::black),1));
        scene->addItem(vertex);
        QString num = QString::number(i+1);
        QGraphicsTextItem* text = new QGraphicsTextItem(num, vertex);
        text->adjustSize();
        text->setPos(getPoint(i, g.V));
        text->setDefaultTextColor(Qt::red);
        //text->setText(num);
       // scene->addItem(text);
    }
}

MainWindow::~MainWindow()
{

}

