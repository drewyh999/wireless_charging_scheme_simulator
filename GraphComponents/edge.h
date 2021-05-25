//
// Created by Dominique Zhu on 2021/3/22.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_EDGE_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_EDGE_H
#include<cmath>
#include "point.h"
#include "vertex.h"
#include<vector>

using namespace std;

class Edge {
    //For a line in the x-y coordinate system, it is generally expressed as y = ax + b
    //It is mandatory to keep the second point of an Edge to be different

private:
    double a; //For a

    double b; //For b

    Vertex *vertex_1;

    Vertex *vertex_2;

    void moveFromVertex(Point *start_point, double distance) const;//Calculate the coordinate for the x_start & y_start
    //after moving for distance on the line direction
public:
    [[nodiscard]] double getYbyX(double x) const;

    [[nodiscard]] double getXbyY(double y) const;

    Edge(Vertex *p_1, Vertex *p_2);//Construct the line by two  Vertex coordinate of
    // the vertices

    [[nodiscard]]  Vertex *getVertex1() const;

    [[nodiscard]]  Vertex *getVertex2() const;

    double chargeAlongEdge(vector<Charger *> *chargers, double delta_l, double P_c, double v_bar) const;

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_EDGE_H
