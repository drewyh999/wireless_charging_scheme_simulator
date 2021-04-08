//
// Created by 朱原昊 on 2021/3/29.
//

#include <graph.h>
#include "base_solution.h"



Graph *BaseSolution::getGraph() const {
    return graph;
}

vector<Charger *> *BaseSolution::getChargerPlacement() const {
    return charger_placement;
}

BaseSolution::BaseSolution(Graph *graph) : graph(graph) {
    charger_placement = new vector<Charger*>();
}
