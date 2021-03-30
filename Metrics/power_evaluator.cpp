//
// Created by 朱原昊 on 2021/3/29.
//

#include "power_evaluator.h"

PowerEvaluator::PowerEvaluator(Solution *solution, double pC) : BaseEvaluator(solution), P_c(pC) {}

double PowerEvaluator::getEvaluationScore() {
    int n =  solution -> getGraph() -> getNumberOfVertices();
    auto vertices =  solution -> getGraph() -> getVertices();
    auto placement =  solution -> getChargerPlacement();
    double sum = 0;
    for(auto & vertex : *vertices){
        double pc_under_ph = vertex -> chargeToPoint(placement);
        sum += pc_under_ph < 1 ? pc_under_ph : 1;
    }
    return sum / n;
}

