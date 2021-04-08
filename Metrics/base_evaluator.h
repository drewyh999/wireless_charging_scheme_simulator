//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
#include"graph.h"
#include "charger.h"

class BaseEvaluator {
protected:
    Graph *graph;
public:
    BaseEvaluator(Graph *graph);

    virtual double getEvaluationScore(vector<Charger*> *placement) = 0;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
