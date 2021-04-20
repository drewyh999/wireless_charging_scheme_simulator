//
// Created by 朱原昊 on 2021/3/22.
//

#include "edge.h"



void Edge::moveFromVertex(Point *start_point, double distance) const {
    double cosine = cos(atan(a));
    double new_x = start_point->getX() + distance * cosine;
    double new_y = getYbyX(new_x);
    start_point->setX(new_x);
    start_point->setY(new_y);
}

double Edge::getYbyX(double x) const {
    return a * x + b;
}

double Edge::getXbyY(double y) const {
    return (y - b) / a;
}

Edge::Edge(Vertex *p_1, Vertex *p_2) {
    vertex_1 = p_1;
    vertex_2 = p_2;
    double x_1 = p_1->getX();
    double y_1 = p_1->getY();
    double x_2 = p_2->getX();
    double y_2 = p_2->getY();
    a = (y_2 - y_1) / (x_2 - x_1);
    b = y_2 - a * x_2;
}

Vertex *Edge::getVertex1() const {
    return vertex_1;
}

Vertex *Edge::getVertex2() const {
    return vertex_2;
}

double Edge::chargeAlongEdge(vector<Charger *> *chargers, double delta_l, double P_c, double v_bar) const {
    Point* start_point = this->getVertex1();
    double vertex_distance = start_point -> getDistance(this->getVertex2());

    int M = vertex_distance / delta_l;

    double travel_time = delta_l / v_bar;
    double E_max = (P_c - start_point -> chargeToPoint(chargers)) * travel_time;
    for(int i = 0;i < M; ++i){
        double temp_E = 0;
        auto temp_point = new Point(start_point->getX(), start_point->getY());
        for(int j = 0;j < i; ++j){
            if(j == 0){
                //First time move it to the 1/2 delta_l away from start Vertex
                moveFromVertex(temp_point, delta_l / 2);
            }
            else{
                //Later we can move it one Sigma long each time to next mid-Vertex
                moveFromVertex(temp_point, delta_l);
            }
            temp_E += (P_c - temp_point->chargeToPoint(chargers)) * travel_time;
        }
        E_max = temp_E > E_max ? temp_E : E_max;
    }
    return E_max;
}
