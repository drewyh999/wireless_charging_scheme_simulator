//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H

#include<iostream>
#include"graph.h"
class BaseSolution {
protected:
    Graph *graph;
    vector<charger*> *charger_placement;
public:

    explicit BaseSolution(Graph *graph);

    [[nodiscard]] Graph *getGraph() const;

    [[nodiscard]] vector<charger *> *getChargerPlacement() const;

    virtual void iterateOptimization() = 0;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H
