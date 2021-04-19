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

int BaseSolution::getNumberOfChargers() const {
    return charger_placement -> size();
}



void BaseSolution::getEvaluationSum_m(evaluation_params &params) {
    auto energy_evaluator = params.energy_evaluator;
    auto chance_evaluator = params.chance_evaluator;
    auto power_evaluator = params.power_evaluator;
    auto placement = params.charger_placement;
    double e_value = energy_evaluator -> getEvaluationScore(placement);
    double c_value = chance_evaluator -> getEvaluationScore(placement);
    double p_value = power_evaluator -> getEvaluationScore(placement);
    double Q = e_value + c_value + p_value;
    params.promiseobj.set_value(Q);
}

double BaseSolution::getEvaluationSum(vector<Charger *> *placement, ChanceEvaluator *chance_evaluator,
                                   EnergyEvaluator *energy_evaluator, PowerEvaluator *power_evaluator) {
    double e_value = energy_evaluator -> getEvaluationScore(placement);
    double c_value = chance_evaluator -> getEvaluationScore(placement);
    double p_value = power_evaluator -> getEvaluationScore(placement);
    double Q = e_value + c_value + p_value;
    return Q;
}
