#include <iostream>
#include <fstream>
#include "simluation.h"

using namespace std;

int main() {
    std::cout << "Simulator by Yuanhao Zhu\nAn undergraduate project directed by Prof. Lin Feng" << std::endl;
    double P_s_constant = 2.0;
    double P_c_constant = 5.0;
    double P_th_constant = 0.9;
//    auto sim_small = new Simulation(Simulation::Small_Scale);
//    sim_small->Run(Simulation::Var_P_s, P_c_constant, P_th_constant);
//    sim_small->Run(Simulation::Var_P_c, P_s_constant, P_th_constant);
//    sim_small->Run(Simulation::Var_P_th, P_s_constant, P_c_constant);
//    sim_small->Run();
    auto sim_large = new Simulation(Simulation::Large_Scale);
    sim_large->Run(Simulation::Var_P_s, P_c_constant, P_th_constant);
    sim_large->Run(Simulation::Var_P_c, P_s_constant, P_th_constant);
    sim_large->Run(Simulation::Var_P_th, P_s_constant, P_c_constant);
//    sim_large -> Run();
    return 0;
}
