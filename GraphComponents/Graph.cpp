//
// Created by 朱原昊 on 2021/3/21.
//

#include "Graph.h"

Graph::Graph() {
    this -> vertices = new vector<vertex>();
}

void Graph::AddVertex(unsigned int x, unsigned int y) {
    auto *v = new vertex(x, y);
    this -> vertices -> push

}
