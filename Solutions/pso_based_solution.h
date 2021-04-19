//
// Created by 朱原昊 on 2021/4/11.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_PSO_BASED_SOLUTION_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_PSO_BASED_SOLUTION_H
#include "base_solution.h"


class PsoBasedSolution: public BaseSolution {
private:
    vector<Charger*>* psoSolver(double Ps, int k,Graph *subgraph,ChanceEvaluator *c_evaluator, PowerEvaluator *p_evaluator, EnergyEvaluator *e_evaluator);
    void subgraphDivisioning();
    vector<Graph *> *subgraphs;
    static vector<double> chargerToCoordinateVector(vector<Charger*>* placement);
    static vector<Charger*>* coordinateVectorToCharger(vector<double> vec, double Ps);
public:
    explicit PsoBasedSolution(Graph *graph);
    void solve(double Ps, double Pc, double eB, double v_bar, double pth) override ;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_PSO_BASED_SOLUTION_H
