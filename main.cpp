#include <iostream>
#include "point.h"
#include "edge.h"
#include "charger.h"
#include "base_evaluator.h"

using namespace std;
int main() {
    std::cout << "Simulator by Yuanhao Zhu\nAn undergraduate project directed by Prof. Lin Feng" << std::endl;
    cout << "Charger test:" << endl;

    Edge *test_edge = new Edge(new Vertex(0, 0), new Vertex(0, 0));
    double P_s = 5;
    auto *c_1 = new charger(1,3,P_s);
    auto *c_2 = new charger(2,1,P_s);
    auto chargers = new vector<charger*>();
    chargers -> push_back(c_1);
    chargers -> push_back(c_2);
    double P_c = 4;
    double v_bar = 0.5;
    auto E_max = test_edge -> chargeAlongEdge(chargers,3,P_c,v_bar);
    cout << "Edge test result is :" << E_max << endl;
    auto a = 0;
    return 0;
}
