//
// Created by Dominique Zhu on 2021/3/29.
//

#include "energy_evaluator.h"


double EnergyEvaluator::getEvaluationScore(vector<Charger*> *placement) {
    double number_of_edges =  graph -> getNumberOfEdges();
    auto edges =  graph-> getEdges();
    double sum = 0;
    double emax = 0;
    double ec_under_emax_minus_eb = 0;
    double part_value = 0;
    double E_c = 0;
    double edge_distance = 0;
    for(auto & edge : *edges){
        emax = edge -> chargeAlongEdge(placement,  delta_l,   P_c,   v_bar);
        edge_distance = edge -> getVertex1() -> getDistance(edge -> getVertex2());
        E_c = P_c * (edge_distance / v_bar);
        ec_under_emax_minus_eb = (emax - E_B) / E_c;
        part_value = (1 - ec_under_emax_minus_eb);
        sum += part_value < 1 ? part_value : 1;
    }
    return sum / number_of_edges;
}

EnergyEvaluator::EnergyEvaluator(Graph *graph, double eB, double deltaL, double pC, double vBar)
        : BaseEvaluator(graph), E_B(eB), delta_l(deltaL), P_c(pC), v_bar(vBar) {
}

