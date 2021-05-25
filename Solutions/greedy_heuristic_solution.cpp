//
// Created by Dominique Zhu on 2021/4/2.
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

    double temp_Q = 0;

    cout << "\nRunning Greedy" << endl;

    cout << "Number of candidated coordinates:" << candidate_coordinates->size() << endl;

    while (Q < 3) {
        auto max_q_candidate = candidate_coordinates->begin();
        for (auto candidate = candidate_coordinates->begin(); candidate != candidate_coordinates->end(); ++candidate) {
            charger_placement->push_back(new Charger((*candidate)->getX(), (*candidate)->getY(), Ps));
            temp_Q = utils::getEvaluationSum(charger_placement, chance_evaluator, energy_evaluator, power_evaluator);
            if (temp_Q > Q) {
                Q = temp_Q;
                max_q_candidate = candidate;
            }
            charger_placement->pop_back();
        }
        charger_placement->push_back(new Charger((*max_q_candidate)->getX(), (*max_q_candidate)->getY(), Ps));

        candidate_coordinates->erase(max_q_candidate);

        utils::printProgress(Q / (double) 3);
    }

}

