//
// Created by Dominique Zhu on 2021/4/19.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_SIMLUATION_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_SIMLUATION_H

#include <iostream>
#include "point.h"
#include "edge.h"
#include "charger.h"
#include "chance_evaluator.h"
#include "greedy_heuristic_solution.h"
#include "pso_based_solution.h"
#include <fstream>

using namespace std;

class Simulation {
private:
    Graph *graph;

    void initSmallScaleGraph();

    void initLargeScaleGraph();

    bool is_large;

    void graphToFile();

    static void placementToFile(vector<Charger *> *placement, const string &name);

public:
    //Indicated simulating small scale simulation or large scale simulation
    enum Case {
        Small_Scale, Large_Scale
    };

    enum VariatedParam {
        Var_P_s, Var_P_c, Var_P_th
    };

    explicit Simulation(Simulation::Case situation);

    // For running simulations that outputs numbers of chargers of the placements
    void Run(VariatedParam v_param, double cons_1, double cons_2);

    // For running simulation that outputs exact coordinates of each chargers
    void Run();
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_SIMLUATION_H
