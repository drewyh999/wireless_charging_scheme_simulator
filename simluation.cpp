//
// Created by 朱原昊 on 2021/4/19.
//

#include "simluation.h"

Simulation::Simulation(Simulation::Case situation) {
    if (situation == Simulation::Case::Large_Scale) {
        initLargeScaleGraph();
        is_large = true;
    }
    if (situation == Simulation::Case::Small_Scale) {
        initSmallScaleGraph();
        is_large = false;
    }
}

void Simulation::initSmallScaleGraph() {
    graph = new Graph();
    auto p_1 = new Vertex(0.3, 1.9);
    auto p_2 = new Vertex(1, 3.3);
    auto p_3 = new Vertex(2.2, 0.3);
    auto p_4 = new Vertex(3.5, 3.2);
    graph->addVertex(p_1);
    graph->addVertex(p_2);
    graph->addVertex(p_3);
    graph->addVertex(p_4);

    graph->addEdge(new Edge(p_1, p_2));
    graph->addEdge(new Edge(p_2, p_3));
    graph->addEdge(new Edge(p_2, p_4));
    graph->addEdge(new Edge(p_1, p_3));
    std::cout << "Small scale graph initiated" << std::endl;
}

void Simulation::initLargeScaleGraph() {
    std::cout << "Large scale graph initiated" << std::endl;
}

void Simulation::Run(Simulation::VariatedParam v_param, double cons_1, double cons_2) {
    ofstream ofile;
    if (is_large)
        ofile.open(string(RESULT_DIRECTORY).append("large_scale_result.txt"), fstream::app);
    else
        ofile.open(string(RESULT_DIRECTORY).append("small_scale_result.txt"), fstream::app);

    switch (v_param) {
        case Var_P_c: {
            cout << "Running simulation rounds on " << "Constant variable: P_s and p_th:" << cons_1 << "," << cons_2
                 << endl;
            ofile << "Constant variable: P_s and p_th:" << cons_1 << " " << cons_2 << endl;
            for (double i = P_C_RANGE_LOW; i <= P_C_RANGE_HIGH; ++i) {
                auto greedy_solution = new GreedyHeuristicSolution(graph, GREEDY_GRANULARITY);
                auto pso_solution = new PsoBasedSolution(graph);
                greedy_solution->solve(cons_1, i * 0.001, BATTERY_CAPACITY, V_BAR, cons_2);
                pso_solution->solve(cons_1, i * 0.001, BATTERY_CAPACITY, V_BAR, cons_2);
                ofile << "With P_c =" << to_string(i) << "greedy solution output:"
                      << greedy_solution->getNumberOfChargers() << " Chargers" << endl;
                ofile << "With P_c =" << to_string(i) << "pso solution output:"
                      << pso_solution->getNumberOfChargers() << " Chargers" << endl;
            }
            break;
        }
        case Var_P_s: {
            cout << "Running simulation rounds on " << "Constant variable: P_c and p_th:" << cons_1 << "," << cons_2
                 << endl;
            ofile << "Constant variable: P_c and p_th:" << cons_1 << " " << cons_2 << endl;
            for (double i = P_S_RANGE_LOW; i <= P_S_RANGE_HIGH; ++i) {
                auto greedy_solution = new GreedyHeuristicSolution(graph, GREEDY_GRANULARITY);
                auto pso_solution = new PsoBasedSolution(graph);
                greedy_solution->solve(i, cons_1 * 0.001, BATTERY_CAPACITY, V_BAR, cons_2);
                pso_solution->solve(i, cons_1 * 0.001, BATTERY_CAPACITY, V_BAR, cons_2);
                ofile << "With P_s =" << to_string(i) << "greedy solution output:"
                      << greedy_solution->getNumberOfChargers() << " Chargers" << endl;
                ofile << "With P_s =" << to_string(i) << "pso solution output:"
                      << pso_solution->getNumberOfChargers() << " Chargers" << endl;
            }
            break;
        }
        case Var_P_th: {
            cout << "Running simulation rounds on " << "Constant variable: P_s and P_c:" << cons_1 << "," << cons_2
                 << endl;
            ofile << "Constant variable: P_s and P_c:" << cons_1 << " " << cons_2 << endl;
            for (double i = P_TH_RANGE_LOW; i <= P_TH_RANGE_HIGH; i = i + 0.05) {
                auto greedy_solution = new GreedyHeuristicSolution(graph, GREEDY_GRANULARITY);
                auto pso_solution = new PsoBasedSolution(graph);
                greedy_solution->solve(cons_1, cons_2 * 0.001, BATTERY_CAPACITY, V_BAR, i);
                pso_solution->solve(cons_1, cons_2 * 0.001, BATTERY_CAPACITY, V_BAR, i);
                ofile << "With p_th =" << to_string(i) << "greedy solution output:"
                      << greedy_solution->getNumberOfChargers() << " Chargers" << endl;
                ofile << "With p_th =" << to_string(i) << "pso solution output:"
                      << pso_solution->getNumberOfChargers() << " Chargers" << endl;
            }
            break;
        }
    }
    ofile.close();
}

void Simulation::Run() {
    double Pth = 0.9;
    double Pc = 0.007;
    double Ps = 2;
    auto greedy_solution = new GreedyHeuristicSolution(graph, GREEDY_GRANULARITY);
    auto pso_solution = new PsoBasedSolution(graph);
    greedy_solution->solve(Ps, Pc, BATTERY_CAPACITY, V_BAR, Pth);
    pso_solution->solve(Ps, Pc, BATTERY_CAPACITY, V_BAR, Pth);
    cout << "Greedy Solution chargers" << endl;
    for (auto &charger : *(greedy_solution->getChargerPlacement())) {
        cout << charger->toString() << endl;
    }
    cout << "Pso Solution chargers" << endl;
    for (auto &charger : *(pso_solution->getChargerPlacement())) {
        cout << charger->toString() << endl;
    }
}
