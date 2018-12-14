#include "graph.h"

Graph::Graph()
{

}

Graph::Graph(int vert, int edges)
{
    this->V = vert;
    this->edge = new Edge[edges];
}
