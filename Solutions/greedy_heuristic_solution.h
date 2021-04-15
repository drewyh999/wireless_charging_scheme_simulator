//
// Created by 朱原昊 on 2021/4/2.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_GREEDY_HEURISTIC_SOLUTION_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_GREEDY_HEURISTIC_SOLUTION_H
#include "base_solution.h"

class GreedyHeuristicSolution: public BaseSolution {
private:
    int granularity;
    vector<Coordinate*> *candidate_coordinates;
public:
    GreedyHeuristicSolution(Graph *graph, int granularity);

    void solve(double Ps, double Pc, double eB, double v_bar, double pth) override ;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_GREEDY_HEURISTIC_SOLUTION_H
