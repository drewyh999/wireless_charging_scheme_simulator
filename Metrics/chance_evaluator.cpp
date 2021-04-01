//
// Created by 朱原昊 on 2021/3/29.
//

#include "chance_evaluator.h"

double ChanceEvaluator::getEvaluationScore() {
    auto edges = solution -> getGraph() -> getEdges();
    auto placement = solution -> getChargerPlacement();
    auto number_of_edges = solution -> getGraph() -> getNumberOfEdges();
    double E_max = 0;
    double P_h = 0;
    double p_no = 0;
    double part_value = 0;
    double sum = 0;
    Vertex *end_vertex;
    for(auto & edge : *edges){
        E_max = edge -> chargeAlongEdge(placement,delta_l,P_c,v_bar);
        end_vertex = edge -> getVertex2();
        P_h = end_vertex -> chargeToPoint(placement);
        part_value = getTruncatedNormalDistributionCdfValue(
                end_vertex -> getMu(),end_vertex -> getSigma(),
                E_max / (P_h - P_c)
                );
        sum += part_value < 1 ? part_value : 1;
    }
    return sum / number_of_edges;
}

double ChanceEvaluator::getTruncatedNormalDistributionCdfValue(double mu, double sigma, double x) {
    boost::math::normal norm(mu,sigma);
    auto cdf_value = cdf(complement(norm,x));
    return cdf_value;
}

ChanceEvaluator::ChanceEvaluator(Solution *solution, double pth, double deltaL, double pC, double vBar)
        : BaseEvaluator(solution), pth(pth), delta_l(deltaL), P_c(pC), v_bar(vBar) {}
