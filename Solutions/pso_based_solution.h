//
// Created by 朱原昊 on 2021/4/11.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_PSO_BASED_SOLUTION_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_PSO_BASED_SOLUTION_H
#include "base_solution.h"

class pso_based_solution:public BaseSolution {
private:
    vector<Charger*>* psoSolver(int k);
    void subgraphDivisioning();
    vector<Graph *> *subgraphs;
public:
    explicit pso_based_solution(Graph *graph);
    void solve(double Ps, double Pc, double eB, double v_bar, double pth) override ;

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_PSO_BASED_SOLUTION_H
