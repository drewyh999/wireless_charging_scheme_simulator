//
// Created by Dominique Zhu on 2021/3/30.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_CONFIG_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_CONFIG_H
#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60
#define MU_RANGE_LOW 2.0
#define MU_RANGE_HIGH 10.0
#define DELTA_L 1.2 //Large scale set 1.2 small scale set 0.25
#define V_BAR 0.5
#define PSO_SUBGRAPH_DIVISION_THRESHOLD 5
#define PSO_POPULATION_SIZE 30
#define PSO_ITERATION_TIME 500
#define PSO_OMEGA 0.8
#define PSO_PHI_P 1.3
#define PSO_PHI_G 1.0
#define P_S_RANGE_LOW 2
#define P_S_RANGE_HIGH 5
#define P_C_RANGE_LOW 2
#define P_C_RANGE_HIGH 10
#define BATTERY_CAPACITY 0.0000306
#define P_TH_RANGE_LOW 0.8
#define P_TH_RANGE_HIGH 1.05
#define GREEDY_GRANULARITY 1 //large scale set to 2 small scale set to 1
#define RESULT_DIRECTORY "../../results/" //The path related to the executive produced by cmake-debug

#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_CONFIG_H
