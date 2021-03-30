//
// Created by 朱原昊 on 2021/3/29.
//

#include <graph.h>
#include "base_solution.h"


Solution::Solution(Graph *graph, std::vector<charger *> *chargerPlacement) : graph(graph),
                                                                             charger_placement(chargerPlacement) {}

Graph *Solution::getGraph() const {
    return graph;
}

vector<charger *> *Solution::getChargerPlacement() const {
    return charger_placement;
}
