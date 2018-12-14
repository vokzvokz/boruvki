#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<fstream>
#include<vector>
#include<set>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

class Graph
{
public:
    int V, E;
    Edge* edge;
    Graph();
    Graph(int vert, int edges);
private:

};

#endif // GRAPH_H
