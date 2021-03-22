//
// Created by 朱原昊 on 2021/3/21.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
#include<vector>
#include "vertex.h"

using namespace std;
class Graph {
public:
    vector<vertex> *vertices;
    Graph();
    void AddVertex(unsigned int x, unsigned int y);

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
