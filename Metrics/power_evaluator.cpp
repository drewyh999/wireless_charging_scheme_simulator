//
// Created by 朱原昊 on 2021/3/29.
//

#include "power_evaluator.h"

PowerEvaluator::PowerEvaluator(double pC) :  P_c(pC) {}

double PowerEvaluator::getEvaluationScore(vector<charger*> *placement) {
    int n =  graph -> getNumberOfVertices();
    auto vertices =  graph -> getVertices();
    double sum = 0;
    for(auto & vertex : *vertices){
        double pc_under_ph = vertex -> chargeToPoint(placement);
        sum += pc_under_ph < 1 ? pc_under_ph : 1;
    }
    return sum / n;
}

