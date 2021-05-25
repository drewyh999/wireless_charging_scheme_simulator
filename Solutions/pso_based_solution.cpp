//
// Created by Dominique Zhu on 2021/4/11.
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
            if (*point_a == *vertex || *point_b == *vertex) {
                subgraph->addEdge(edge);
            }
        }
        subgraphs -> push_back(subgraph);
    }
}

vector<Charger*>*
PsoBasedSolution::psoSolver(double Ps, int k, Graph *subgraph, ChanceEvaluator *c_evaluator, PowerEvaluator *p_evaluator, EnergyEvaluator *e_evaluator) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 1);

    double x_center = (*subgraph->getVertices())[0]->getX();
    double y_center = (*subgraph->getVertices())[0]->getY();

    double l_max = 0;
    double l_temp = 0;
    for (auto &edge : *(subgraph->getEdges())) {
        l_temp = edge->getVertex2()->getDistance(edge->getVertex1());
        l_max = l_temp > l_max ? l_temp : l_max;
    }
    double x_min = x_center - l_max;
    double x_max = x_center + l_max;
    double y_min = y_center - l_max;
    double y_max = y_center + l_max;

    vector<double> init_particle;

    for (int i = 0; i < k; i++) {
        init_particle.push_back(x_center);
        init_particle.push_back(y_center);
    }
    // vector holding global best position
    vector<double> global_best(init_particle);

    //vector holding personal best position
    vector<vector<double>> personal_best(PSO_POPULATION_SIZE, init_particle);

    // The vector containing all particle positions
    vector<vector<double>> particle_positions(PSO_POPULATION_SIZE);

    for (int i = 0; i < PSO_POPULATION_SIZE; i++) {
        for (int j = 0; j < k; j++) {
            particle_positions[i].push_back(x_min + dist(mt) * (x_max - x_min));
            particle_positions[i].push_back(y_min + dist(mt) * (y_max - y_min));
        }
    }

    vector<vector<double>> particle_speed(PSO_POPULATION_SIZE, vector<double>(2 * k, 0));

    double Q = 0;

    double max_Q_global = 0;

    vector<double> max_Q_personal(PSO_POPULATION_SIZE, 0);

    auto current_placement_vector = utils::chargerToCoordinateVector(charger_placement);

//    cout << "\nRunning PSO at K = " << k << endl;

    auto pso_omega = (double) PSO_OMEGA;

    auto pso_phi_p = (double) PSO_PHI_P;

    auto pso_phi_g = (double) PSO_PHI_G;

    for (int iter = 0; iter < PSO_ITERATION_TIME; ++iter) {
        for (int p_i = 0; p_i < PSO_POPULATION_SIZE; ++p_i) {
            vector<double> temp_vec(current_placement_vector);
            for (int j = 0; j < 2 * k; ++j) {
//                double pre_speed = particle_speed[p_i][j];
//                double pre_position = particle_positions[p_i][j];
                particle_speed[p_i][j] = pso_omega * particle_speed[p_i][j]
                                         + pso_phi_p * dist(mt) * (personal_best[p_i][j] - particle_positions[p_i][j])
                                         + pso_phi_g * dist(mt) * (global_best[j] - particle_positions[p_i][j]);
                particle_positions[p_i][j] += particle_speed[p_i][j];
//                if(particle_speed[p_i][j] > 30 || particle_positions[p_i][j] > 70 || particle_speed[p_i][j] < -30){
//                    cout << "\nOuch! there seems to be a problem at iter "<< iter << endl;
//                    cout << "Previous speed:" << pre_speed << endl;
//                    cout << "personal_best[p_i][j] - particle_positions[p_i][j]:" << personal_best[p_i][j] - pre_position << endl;
//                    cout << "global_best[j] - particle_positions[p_i][j]" << global_best[j] - pre_position << endl;
//                    cout << "Previous position " << pre_position << endl;
//                    cout << "Previous speed" << pre_speed << endl;
//                }
                temp_vec.push_back(particle_positions[p_i][j]);
//
            }
            auto temp_placement = utils::coordinateVectorToCharger(temp_vec, Ps);
            Q = utils::getEvaluationSum(temp_placement, c_evaluator, e_evaluator, p_evaluator);
            if(Q > max_Q_global){
                max_Q_global = Q;
                global_best.assign(particle_positions[p_i].begin(),particle_positions[p_i].end());
            }
            if(Q > max_Q_personal[p_i]){
                max_Q_personal[p_i] = Q;
                personal_best[p_i].assign(particle_positions[p_i].begin(),particle_positions[p_i].end());
            }

        }
        utils::printProgress(iter / (double) PSO_ITERATION_TIME);
    }

//    cout << "\nGlobal best positions ";
    for(auto & item : global_best){
        current_placement_vector.push_back(item);
//        cout << to_string(item) << " ";
    }
//    cout << endl;
    return utils::coordinateVectorToCharger(current_placement_vector, Ps);
}

void PsoBasedSolution::solve(double Ps, double Pc, double eB, double v_bar, double pth) {
    int k = 0;

    double Q = 0;

    cout << "Running Pso with subgraphs size of " << subgraphs->size() << endl;

    for (auto &subgraph : *subgraphs) {
        k = 0;
        auto chance_evaluator = new ChanceEvaluator(subgraph, pth, DELTA_L, Pc, v_bar);
        auto energy_evaluator = new EnergyEvaluator(subgraph, eB, DELTA_L, Pc, v_bar);
        auto power_evaluator = new PowerEvaluator(subgraph, Pc);
        Q = utils::getEvaluationSum(charger_placement, chance_evaluator, energy_evaluator, power_evaluator);
//        cout << "\nSubgraph Q is " << to_string(Q) << endl;
        auto new_placement = new vector<Charger *>();
//        cout << "Solving subgraph with center of "<< (*subgraph -> getVertices())[0] -> toString() << endl;
//        cout << "Subgraph number of vertex " << subgraph -> getNumberOfVertices() <<"Number of edges " << subgraph -> getNumberOfEdges()<< endl;
        bool subgraph_need_to_be_solved = false; // If the subgraph needs extra chargers,
        // then the current placement should be assigned as the new placement
        while (Q < (double) 3.0) {
            subgraph_need_to_be_solved = true;
            auto start = std::chrono::system_clock::now();
            k += 1;
            utils::printProgress(Q / (double) 3.0);
            new_placement = psoSolver(Ps, k, subgraph, chance_evaluator, power_evaluator, energy_evaluator);
//            temp_placement = new vector<Charger*>();
//            temp_placement ->assign(charger_placement -> begin(),charger_placement -> end());
//            temp_placement ->insert(temp_placement -> end(),new_placement -> begin(), new_placement -> end());
//            cout << "\nnumber of c_p " << charger_placement -> size() <<endl;
//            cout << "number of t_p " << temp_placement -> size() << endl;
//            cout << "number of d_p " << new_placement -> size() << endl;
//            cout << "k " << k << endl;
//            for(auto & charger : *new_placement){
//                cout << charger -> toString() << endl;
//            }
            Q = utils::getEvaluationSum(new_placement, chance_evaluator, energy_evaluator, power_evaluator);
//            cout << "Current Q is " << to_string(Q) << endl;
//            auto end   = std::chrono::system_clock::now();
//            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//            cout <<  "Pso iteration took "
//                 << double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den
//                 << " seconds" << endl;
        }
        utils::printProgress(1);
        if (subgraph_need_to_be_solved) {
            charger_placement->assign(new_placement->begin(), new_placement->end());
        }
    }
}

