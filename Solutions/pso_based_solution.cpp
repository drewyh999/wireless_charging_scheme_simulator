//
// Created by 朱原昊 on 2021/4/11.
//

#include "pso_based_solution.h"


PsoBasedSolution::PsoBasedSolution(Graph *graph) : BaseSolution(graph) {
    subgraphs = new vector<Graph*>();
    if(graph -> getNumberOfVertices() > PSO_SUBGRAPH_DIVISION_THRESHOLD){
        subgraphDivisioning();
    }
    else{
        subgraphs -> push_back(graph);
    }
}

void PsoBasedSolution::subgraphDivisioning() {
    auto vertices = graph -> getVertices();
    auto edges = graph -> getEdges();
    sort(vertices->begin(),vertices->end(),Vertex::comp);
    for(auto & vertex : *vertices){
        //Every sub-graph is composed with a unique vertex
        auto subgraph = new Graph();
        subgraph -> addVertex(vertex);
        //Find out each sub-graph components
        //Each sub-graph is composed of a unique vertex and its outgoing edges.
        //So we only add its outgoing edges to the sub-graph
        for(auto * edge : *edges){
            auto point_a = edge -> getVertex1();
            auto point_b = edge -> getVertex2();
            if(point_a == vertex){
                subgraph -> addEdge(edge);
            }
            else if(point_b == vertex){
                subgraph -> addEdge(edge);
            }
        }
        subgraphs -> push_back(subgraph);
    }
}

vector<Charger*>*
PsoBasedSolution::psoSolver(double Ps, int k, Graph *subgraph, ChanceEvaluator *c_evaluator, PowerEvaluator *p_evaluator, EnergyEvaluator *e_evaluator){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 1);
    // Get the boundary length of the subarea
    double l_max = 0;
    double l_temp = 0;
    for(auto & edge : *(subgraph -> getEdges())){
        l_temp = edge -> getVertex2() -> getDistance(edge -> getVertex1());
        l_max =  l_temp > l_max ? l_temp : l_max;
    }
    double x_center = (*subgraph -> getVertices())[0] -> getX();
    double y_center = (*subgraph -> getVertices())[0] -> getY();
    double x_min = x_center - l_max;
    double x_max = x_center + l_max;
    double y_min = y_center - l_max;
    double y_max = y_center + l_max;

    // vector holding global best position
    vector<int> global_best(2 * k);

    vector<int> init_particle;

    for(int i = 0; i < k;i ++){
        init_particle.push_back(x_center);
        init_particle.push_back(y_center);
    }

    // The vector containing all particle_position
    vector<vector<int>> particle_positions(PSO_POPULATION_SIZE, init_particle);

    vector<int> personal_best(2 * k);

    vector<vector<int>> particle_speed(PSO_POPULATION_SIZE, vector<int>(2 * k, 0));

    double Q = 0;

    double max_Q_global = 0;

    vector<int> max_Q_personal(PSO_POPULATION_SIZE,0);

    auto current_placement_vector = chargerToCoordinateVector(charger_placement);

    for(int iter = 0; iter < PSO_ITERATION_TIME; ++iter){
        for(int p_i = 0; p_i < PSO_POPULATION_SIZE; ++p_i){
            vector<int> temp_vec(current_placement_vector);
            for(int j = 0;j < 2 * k; ++j){
                particle_speed[p_i][j] = PSO_OMEGA * particle_speed[p_i][j]
                                         + PSO_PHI_P * dist(mt) * (personal_best[j] - particle_positions[p_i][j])
                                         + PSO_PHI_G * dist(mt) * (global_best[j] - particle_positions[p_i][j]);
                particle_positions[p_i][j] += particle_speed[p_i][j];
                temp_vec.push_back(particle_positions[p_i][j]);
            }
            auto temp_placement = coordinateVectorToCharger(temp_vec,Ps);
            Q = getEvaluationSum(temp_placement,c_evaluator,e_evaluator,p_evaluator) ;
            max_Q_global = max_Q_global < Q ? Q : max_Q_global;
            max_Q_personal[p_i] = max_Q_personal[p_i] < Q ? Q : max_Q_personal[p_i];
        }
    }

    for(auto & item : global_best){
        current_placement_vector.push_back(item);
    }
    return coordinateVectorToCharger(current_placement_vector,Ps);
}

void PsoBasedSolution::solve(double Ps, double Pc, double eB, double v_bar, double pth) {
    int k = 0;

    double Q = 0;

    for(auto & subgraph : *subgraphs){
        k = 0;
        auto chance_evaluator = new ChanceEvaluator(subgraph, pth, DELTA_L, Pc, v_bar);
        auto energy_evaluator = new EnergyEvaluator(subgraph, eB, DELTA_L, Pc, v_bar);
        auto power_evaluator = new PowerEvaluator(subgraph, Pc);
        Q = getEvaluationSum(charger_placement, chance_evaluator, energy_evaluator, power_evaluator);
        auto temp_placement = new vector<Charger*>();
        while(Q < 3){
            k += 1;
            temp_placement = psoSolver(Ps,k,subgraph,chance_evaluator,power_evaluator,energy_evaluator);
            Q = getEvaluationSum(temp_placement, chance_evaluator,energy_evaluator, power_evaluator);
        }
        charger_placement = temp_placement;
    }
}

vector<int> PsoBasedSolution::chargerToCoordinateVector(vector<Charger *>* placement) {
    vector<int> result;
    for(auto * charger : *placement){
        result.push_back(charger -> getX());
        result.push_back(charger -> getY());
    }
    return result;
}

vector<Charger *> *PsoBasedSolution::coordinateVectorToCharger(vector<int> vec, double Ps) {
    auto result = new vector<Charger*>();
    int i = 0;
    while(i < vec.size()){
        result -> push_back(new Charger(vec[i],vec[i + 1],Ps));
        i += 2;
    }
    return result;
}


