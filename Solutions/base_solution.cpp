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

int BaseSolution::getEvaluationSum(vector<Charger *> *charger_placement, ChanceEvaluator *chance_evaluator,
                                   EnergyEvaluator *energy_evaluator, PowerEvaluator *power_evaluator) {
    double e_value = energy_evaluator -> getEvaluationScore(charger_placement);
    double c_value = chance_evaluator -> getEvaluationScore(charger_placement);
    double p_value = power_evaluator -> getEvaluationScore(charger_placement);
    auto Q = e_value + c_value + p_value;
    return Q;
}
