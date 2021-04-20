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
    cout << "Trying to Set Q to " << to_string(Q) << endl;
    params.promiseobj.set_value(Q);
    cout << "Set Q to " << to_string(Q) << endl;
}

double BaseSolution::getEvaluationSum(vector<Charger *> *placement, ChanceEvaluator *chance_evaluator,
                                   EnergyEvaluator *energy_evaluator, PowerEvaluator *power_evaluator) {
    packaged_task<double()> energyTask(bind(std::mem_fn(&EnergyEvaluator::getEvaluationScore),energy_evaluator,placement));
    auto e_future = energyTask.get_future();
    auto th = new thread(move(energyTask));

//    double e_value = energy_evaluator -> getEvaluationScore(placement);
//    double c_value = chance_evaluator -> getEvaluationScore(placement);
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
