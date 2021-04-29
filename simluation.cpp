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
    graph = new Graph();
    auto a = new Vertex(2, 3);
    auto b = new Vertex(6.2, 17.8);
    auto c = new Vertex(3.48, 13);
    auto d = new Vertex(11.46, 8.57);
    auto e = new Vertex(12, 46);
    auto f = new Vertex(5.4, 41.2);
    auto g = new Vertex(20, 40);
    auto h = new Vertex(54.82, 7.03);
    auto i = new Vertex(27.12, 20.88);
    auto j = new Vertex(37.89, 44.52);
    auto k = new Vertex(15.37, 34.58);
    auto l = new Vertex(47.13, 5.07);
    auto m = new Vertex(47.97, 48.85);
    auto n = new Vertex(54.68, 32.35);
    auto o = new Vertex(47.13, 40.88);
    auto p = new Vertex(40, 20);
    graph->addVertex(a);
    graph->addVertex(b);
    graph->addVertex(c);
    graph->addVertex(d);
    graph->addVertex(e);
    graph->addVertex(f);
    graph->addVertex(g);
    graph->addVertex(h);
    graph->addVertex(i);
    graph->addVertex(j);
    graph->addVertex(k);
    graph->addVertex(l);
    graph->addVertex(m);
    graph->addVertex(n);
    graph->addVertex(o);
    graph->addVertex(p);


    graph->addEdge(new Edge(a, d));
    graph->addEdge(new Edge(d, c));
    graph->addEdge(new Edge(d, f));
    graph->addEdge(new Edge(d, e));
    graph->addEdge(new Edge(d, k));
    graph->addEdge(new Edge(j, i));
    graph->addEdge(new Edge(l, h));
//    graph->addEdge(new Edge(q,o));
    graph->addEdge(new Edge(p, o));
//    graph->addEdge(new Edge(n,q));
    graph->addEdge(new Edge(o, m));
    graph->addEdge(new Edge(n, o));
//    graph->addEdge(new Edge(q,l));
    graph->addEdge(new Edge(c, f));
    graph->addEdge(new Edge(i, p));
    graph->addEdge(new Edge(p, l));
    graph->addEdge(new Edge(j, m));
    graph->addEdge(new Edge(i, k));
//    graph->addEdge(new Edge(i,t));
//    graph->addEdge(new Edge(p,q));
    graph->addEdge(new Edge(i, g));
//    graph->addEdge(new Edge(g,t));
//    graph->addEdge(new Edge(t,s));
//    graph->addEdge(new Edge(s,m));
    graph->addEdge(new Edge(m, n));
//    graph->addEdge(new Edge(t,j));
//    graph->addEdge(new Edge(r,g));
    graph->addEdge(new Edge(k, g));
    graph->addEdge(new Edge(f, e));
    graph->addEdge(new Edge(e, k));
    graph->addEdge(new Edge(c, b));

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
    double Pth = 0.8;
    double Pc = 0.003;
    double Ps = 5;
    graphToFile();
    auto greedy_solution = new GreedyHeuristicSolution(graph, GREEDY_GRANULARITY);
    auto pso_solution = new PsoBasedSolution(graph);
    greedy_solution->solve(Ps, Pc, BATTERY_CAPACITY, V_BAR, Pth);
    pso_solution->solve(Ps, Pc, BATTERY_CAPACITY, V_BAR, Pth);

    cout << "Greedy Solution chargers: " << greedy_solution->getNumberOfChargers() << " chargers placed" << endl;
    placementToFile(greedy_solution->getChargerPlacement(), "greedySolution");
    cout << "Pso Solution chargers" << pso_solution->getNumberOfChargers() << " chargers placed" << endl;

    placementToFile(pso_solution->getChargerPlacement(), "psoSolution");
}

void Simulation::graphToFile() {
    ofstream outfile;
    outfile.open(string(RESULT_DIRECTORY).append("large_scale_graph_information.txt"), ios::out);
    if (outfile.good()) {
        outfile << "vertices" << endl;
        for (auto &vertex: *graph->getVertices()) {
            outfile << to_string(vertex->getX()) << ',';
        }
        outfile << endl;
        for (auto &vertex: *graph->getVertices()) {
            outfile << to_string(vertex->getY()) << ',';
        }
        outfile << "\n";
        outfile << "edges" << endl;
        for (auto &edge: *graph->getEdges()) {
            outfile << edge->getVertex1()->toString() << ',' << edge->getVertex2()->toString() << endl;
        }
    }
    outfile.close();
}

void Simulation::placementToFile(vector<Charger *> *placement, const string &name) {
    ofstream outfile;
    outfile.open(string(RESULT_DIRECTORY).append(name).append(".txt"), ios::out);
    if (outfile.good()) {
        for (auto &charger: *placement) {
            outfile << charger->toString() << endl;
        }
    }
    outfile.close();
}


