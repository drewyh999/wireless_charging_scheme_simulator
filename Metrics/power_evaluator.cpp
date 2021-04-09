//
// Created by 朱原昊 on 2021/3/29.
//

#include "power_evaluator.h"



double PowerEvaluator::getEvaluationScore(vector<Charger*> *placement) {
    int n =  graph -> getNumberOfVertices();
    auto vertices =  graph -> getVertices();
    double sum = 0;
    for(auto & vertex : *vertices){
        double pc_under_ph = (vertex -> chargeToPoint(placement)) / P_c;
        sum += pc_under_ph < 1 ? pc_under_ph : 1;
    }
    return sum / n;
}

PowerEvaluator::PowerEvaluator(Graph *graph, double pC) : BaseEvaluator(graph), P_c(pC) {}

