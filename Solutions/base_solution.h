//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H

#include<iostream>
#include"graph.h"
#include "chance_evaluator.h"
#include "energy_evaluator.h"
#include "power_evaluator.h"
#include "config.h"

class BaseSolution {
protected:
    Graph *graph;
    vector<Charger*> *charger_placement;
public:

    explicit BaseSolution(Graph *graph);

    [[nodiscard]] Graph *getGraph() const;

    [[nodiscard]] vector<Charger *> *getChargerPlacement() const;

    [[nodiscard]] int getNumberOfChargers() const;

    // The parameters Ps, Pc, eB, v_bar could be controlled variables and varies through different iterations
    // of a simulation
    //Delta L and Mu , Sigma is supposed to constant during one simulation.
    virtual void solve(double Ps, double Pc, double eB, double v_bar, double pth) = 0;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H
