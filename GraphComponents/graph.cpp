//
// Created by 朱原昊 on 2021/3/21.
//

#include "graph.h"

Graph::Graph() {
    this -> vertices = new vector<Vertex*>();
    this -> Edges = new vector<Edge*>();
}

void Graph::addVertex(Vertex *new_vertex)  {
    this -> vertices-> push_back(new_vertex);
}

void Graph::addEdge(Edge* new_edge) {
    this -> Edges -> push_back(new_edge);
}

vector<Vertex *> *Graph::getVertices() const {
    return vertices;
}

vector<Edge *> *Graph::getEdges() const {
    return Edges;
}

int Graph::getNumberOfEdges() {
    return this -> Edges -> size();
}

int Graph::getNumberOfVertices() {
    return this -> vertices -> size();
}


