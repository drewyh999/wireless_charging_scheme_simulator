//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_ENERGY_EVALUATOR_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_ENERGY_EVALUATOR_H
#include "base_evaluator.h"

class EnergyEvaluator: public BaseEvaluator{
private:
    double E_B;
    double delta_l;
    double P_c;
    double v_bar;
    double E_c;
public:
    EnergyEvaluator(Graph *graph, double eB, double deltaL, double pC, double vBar);

    double getEvaluationScore(vector<Charger*> *placement) override ;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_ENERGY_EVALUATOR_H
