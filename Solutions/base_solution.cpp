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


double BaseSolution::getEvaluationSum(vector<Charger *> *placement, ChanceEvaluator *chance_evaluator,
                                   EnergyEvaluator *energy_evaluator, PowerEvaluator *power_evaluator) {
    packaged_task<double()> energyTask(bind(std::mem_fn(&EnergyEvaluator::getEvaluationScore),energy_evaluator,placement));
    auto e_future = energyTask.get_future();
    auto th = new thread(move(energyTask));
    packaged_task<double()> chanceTask(bind(std::mem_fn(&ChanceEvaluator::getEvaluationScore),chance_evaluator,placement));
    auto c_future = chanceTask.get_future();
    auto th_2 = new thread(move(chanceTask));
    e_future.wait();
    double e_value = e_future.get();
    c_future.wait();
    double c_value = c_future.get();
    double p_value = power_evaluator -> getEvaluationScore(placement);
    double Q = e_value + c_value + p_value;
    th->join();
    th_2->join();
    return Q;
}
