//
// Created by 朱原昊 on 2021/4/2.
//

#include "greedy_heuristic_solution.h"




GreedyHeuristicSolution::GreedyHeuristicSolution(Graph *graph, int granularity) : BaseSolution(graph),
                                                                                  granularity(granularity) {
    auto vertice = graph -> getVertices();
    double max_x = 0;
    double max_y = 0;
    for(auto & vertex : *vertice){
        max_x = vertex -> getX() > max_x ? vertex -> getX() : max_x;
        max_y = vertex -> getY() > max_y ? vertex -> getY() : max_y;
    }
    max_x += granularity;
    max_y += granularity;
    double charger_x = granularity / 2.0;
    double charger_y = granularity / 2.0;
    candidate_coordinates = new vector<Coordinate*>();
    while(charger_x <= max_x){
        charger_y = granularity / 2.0;
        while(charger_y <= max_y){
            candidate_coordinates -> push_back(new Coordinate(charger_x, charger_y));
            charger_y += granularity;
        }
        charger_x += granularity;
    }
}

void GreedyHeuristicSolution::solve(double Ps, double Pc, double eB, double v_bar, double pth) {
    auto chance_evaluator = new ChanceEvaluator(graph, pth, DELTA_L, Pc, v_bar);
    auto energy_evaluator = new EnergyEvaluator(graph, eB, DELTA_L, Pc, v_bar);
    auto power_evaluator = new PowerEvaluator(graph, Pc);

    double Q = 0;

    double e_value = 0;

    double c_value = 0;

    double p_value = 0;

    while(Q < 3){
        auto max_q_candidate = candidate_coordinates -> begin();
        for(auto candidate = candidate_coordinates -> begin();candidate != candidate_coordinates -> end(); ++ candidate){
            charger_placement -> push_back(new Charger((*candidate) -> getX(),(*candidate) -> getY(),Ps));
            e_value = energy_evaluator -> getEvaluationScore(charger_placement);
            c_value = chance_evaluator -> getEvaluationScore(charger_placement);
            p_value = power_evaluator -> getEvaluationScore(charger_placement);
            if(e_value + c_value + p_value > Q){
                Q = e_value + c_value + p_value;
                max_q_candidate = candidate;
            }
            charger_placement -> pop_back();
        }
        std::cout << "With the e_value of " << e_value << "\nc_value of " << c_value << "\np_value of " << p_value << endl;
        //Add the charger that maximize Q to the charger placement set
        std::cout << "Adding candidate to charger set" << (*max_q_candidate) -> toString()  << endl;
        charger_placement -> push_back(new Charger((*max_q_candidate) -> getX(),(*max_q_candidate) -> getY(),Ps));
        //One charger could placed at a candidate coordinate
        candidate_coordinates -> erase(max_q_candidate);
    }

}

