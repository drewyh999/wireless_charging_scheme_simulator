//
// Created by 朱原昊 on 2021/4/11.
//

#include "pso_based_solution.h"


pso_based_solution::pso_based_solution(Graph *graph) : BaseSolution(graph) {
    subgraphs = new vector<Graph*>();
    if(graph -> getNumberOfVertices() > PSO_SUBGRAPH_DIVISION_THRESHOLD){
        subgraphDivisioning();
    }
    else{
        subgraphs -> push_back(graph);
    }
}

void pso_based_solution::subgraphDivisioning() {
    auto vertices = graph -> getVertices();
    auto edges = graph -> getEdges();
    sort(vertices->begin(),vertices->end(),Vertex::comp);
    for(auto & vertex : *vertices){
        //Every sub-graph is composed with a unique vertex
        auto subgraph = new Graph();
        subgraph -> addVertex(vertex);
        //Find out each sub-graph components
        for(auto * edge : *edges){
            auto point_a = edge -> getVertex1();
            auto point_b = edge -> getVertex2();
            if(point_a == vertex){
                subgraph -> addEdge(edge);
                subgraph -> addVertex(point_b);
            }
            else if(point_b == vertex){
                subgraph -> addEdge(edge);
                subgraph -> addVertex(point_a);
            }
        }
        subgraphs -> push_back(subgraph);
    }
}

vector<Charger*>* pso_based_solution::psoSolver(int k) {
    auto temp_placement = new vector<Charger*>();
    return temp_placement;
    //TODO Finish the pso solver
}

void pso_based_solution::solve(double Ps, double Pc, double eB, double v_bar, double pth) {
    int k = 0;

    double Q = 0;

    double e_value = 0;

    double c_value = 0;

    double p_value = 0;

    for(auto & subgraph : *subgraphs){
        k = 0;
        auto chance_evaluator = new ChanceEvaluator(subgraph, pth, DELTA_L, Pc, v_bar);
        auto energy_evaluator = new EnergyEvaluator(subgraph, eB, DELTA_L, Pc, v_bar);
        auto power_evaluator = new PowerEvaluator(subgraph, Pc);
        e_value = energy_evaluator->getEvaluationScore(charger_placement);
        c_value = chance_evaluator->getEvaluationScore(charger_placement);
        p_value = power_evaluator->getEvaluationScore(charger_placement);
        Q = e_value + c_value + p_value;
        auto temp_placement = new vector<Charger*>();
        while(Q < 3){
            k += 1;
            temp_placement = psoSolver(k);
            e_value = energy_evaluator->getEvaluationScore(temp_placement);
            c_value = chance_evaluator->getEvaluationScore(temp_placement);
            p_value = power_evaluator->getEvaluationScore(temp_placement);
            Q = e_value + c_value + p_value;
        }
        charger_placement = temp_placement;
    }
}


