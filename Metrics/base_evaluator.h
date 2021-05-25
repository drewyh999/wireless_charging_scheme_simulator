//
// Created by Dominique Zhu on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
#include"graph.h"
#include "charger.h"
#include<future>

class BaseEvaluator {
protected:
    Graph *graph;
public:
    explicit BaseEvaluator(Graph *graph);

    virtual double getEvaluationScore(vector<Charger*> *placement) = 0;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
