//
// Created by 朱原昊 on 2021/3/21.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
#include<vector>
#include "vertex.h"
#include<map>

using namespace std;
class Graph {
public:
    vector<vertex*> *vertices;
    map<vertex*, bool> iteration_map;
    Graph();
    void AddVertex(vertex* new_vertex) const;
    bool isVertexIterated(vertex* v);

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
