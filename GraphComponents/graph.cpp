//
// Created by 朱原昊 on 2021/3/21.
//

#include "graph.h"

Graph::Graph() {
    this -> vertices = new vector<Vertex*>();
    this -> Edges = new vector<edge*>();
}

void Graph::addVertex(Vertex *new_vertex)  {
    this -> vertices-> push_back(new_vertex);
}

void Graph::addEdge(edge* new_edge) {
    this -> Edges -> push_back(new_edge);
}


