//
// Created by 朱原昊 on 2021/4/20.
//

#include "utils.h"

void utils::printProgress(double percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

vector<double> utils::chargerToCoordinateVector(vector<Charger *> *placement) {
    vector<double> result;
    for (auto *charger : *placement) {
        result.push_back(charger->getX());
        result.push_back(charger->getY());
    }
    return result;
}

vector<Charger *> *utils::coordinateVectorToCharger(vector<double> vec, double Ps) {
    auto result = new vector<Charger *>();
    int i = 0;
    while (i < vec.size()) {
        result->push_back(new Charger(vec[i], vec[i + 1], Ps));
        i += 2;
    }
    return result;
}

double utils::getEvaluationSum(vector<Charger *> *placement, ChanceEvaluator *chance_evaluator,
                               EnergyEvaluator *energy_evaluator, PowerEvaluator *power_evaluator) {
    packaged_task<double()> energyTask(
            bind(std::mem_fn(&EnergyEvaluator::getEvaluationScore), energy_evaluator, placement));
    auto e_future = energyTask.get_future();
    auto th = new thread(move(energyTask));
    packaged_task<double()> chanceTask(
            bind(std::mem_fn(&ChanceEvaluator::getEvaluationScore), chance_evaluator, placement));
    auto c_future = chanceTask.get_future();
    auto th_2 = new thread(move(chanceTask));
    e_future.wait();
    double e_value = e_future.get();
    c_future.wait();
    double c_value = c_future.get();
    double p_value = power_evaluator->getEvaluationScore(placement);
    double Q = e_value + c_value + p_value;
    th->join();
    th_2->join();
    return Q;
}
