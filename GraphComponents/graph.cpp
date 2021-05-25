//
// Created by Dominique Zhu on 2021/3/21.
//

#include "graph.h"

Graph::Graph() {
     vertices = new vector<Vertex*>();
     Edges = new vector<Edge*>();
}

void Graph::addVertex(Vertex *new_vertex)  {
     vertices-> push_back(new_vertex);
}

void Graph::addEdge(Edge* new_edge) {
     Edges -> push_back(new_edge);
     generateDegree();
}

vector<Vertex *> *Graph::getVertices() const {
    return vertices;
}

vector<Edge *> *Graph::getEdges() const {
    return Edges;
}

int Graph::getNumberOfEdges() {
    return  Edges -> size();
}

int Graph::getNumberOfVertices() {
    return  vertices -> size();
}

void Graph::generateDegree() {
    for(auto & vertex : *vertices) {
        int sum = 0;
        for (auto &edge  : *Edges) {
            if (*(edge->getVertex2()) == (*vertex) || *(edge->getVertex1()) == *(vertex)) {
                sum++;
            }
        }
        vertex->setDegree(sum);
    }
}


