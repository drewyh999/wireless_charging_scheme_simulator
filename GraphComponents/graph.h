//
// Created by 朱原昊 on 2021/3/21.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
#include<vector>
#include "vertex.h"
#include<map>
#include"edge.h"

using namespace std;
class Graph {
private:
    vector<Vertex*> *vertices;
    vector<Edge*> *Edges;
public:

    Graph();

    void addVertex(Vertex* new_vertex);

    void addEdge(Edge* new_edge);

    int getNumberOfEdges();

    int getNumberOfVertices();

    [[nodiscard]] vector<Vertex *> *getVertices() const;

    [[nodiscard]] vector<Edge *> *getEdges() const;

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_GRAPH_H
