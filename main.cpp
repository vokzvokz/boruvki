#include "mainwindow.h"
#include <QApplication>
#include <QFile>
//#include "graph.h"
#include <QtDebug>

// Boruvka's algorithm to find Minimum Spanning
// Tree of a given connected, undirected and
// weighted graph
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;


Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ifstream f("testGraph.txt");
    int n, e;
    f>>n>>e;
    Graph* graph = createGraph(n, e);

    for(int i = 0; i<e; i++){
        f>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
        qDebug()<<graph->edge[i].src<<" - "<<graph->edge[i].dest<<" added";
    }

    MainWindow w(graph);
    w.show();

    return a.exec();
}
