#include <iostream>
#include "point.h"
#include "edge.h"
#include "charger.h"
#include "chance_evaluator.h"
#include "greedy_heuristic_solution.h"
using namespace std;
int main() {
    std::cout << "Simulator by Yuanhao Zhu\nAn undergraduate project directed by Prof. Lin Feng" << std::endl;
    auto graph = new Graph();
    auto p_1 = new Vertex(0.3,1.9);
    auto p_2 = new Vertex(1,3.3);
    auto p_3 = new Vertex(2.2,0.3);
    auto p_4 = new Vertex(3.5,3.2);
    graph -> addVertex(p_1);
    graph -> addVertex(p_2);
    graph -> addVertex(p_3);
    graph -> addVertex(p_4);

    graph -> addEdge(new Edge(p_1, p_2));
    graph -> addEdge(new Edge(p_2,p_3));
    graph -> addEdge(new Edge(p_2,p_4));
    graph -> addEdge(new Edge(p_1,p_3));

    auto solution = new GreedyHeuristicSolution(graph,1);

    solution -> solve(2,0.007,0.000027,V_BAR,0.9);

    cout << "Solution test:" << endl;
    for(auto & charger: *(solution -> getChargerPlacement())){
        cout << charger -> toString() << endl;
    }

    return 0;
}
