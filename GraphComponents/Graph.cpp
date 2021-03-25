//
// Created by 朱原昊 on 2021/3/21.
//

#include "Graph.h"

Graph::Graph() {
    this -> vertices = new vector<vertex*>();
}

bool Graph::isVertexIterated(vertex *v) {
    return this -> iteration_map.at(v);
}

void Graph::AddVertex(vertex *new_vertex) const {
    this -> vertices-> push_back(new_vertex);
}


