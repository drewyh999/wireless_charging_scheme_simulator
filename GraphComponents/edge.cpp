//
// Created by 朱原昊 on 2021/3/22.
//

#include "edge.h"



Point* Edge::moveFromVertex(Point* start_point, double distance) const {
    double cosine = cos(atan(this -> a));
    double new_x = start_point -> getX() + distance * cosine;
    double new_y = this -> getYbyX(new_x);
    return new Point(new_x, new_y);
}

double Edge::getYbyX(double x) const {
    return this -> a * x + this -> b;
}

double Edge::getXbyY(double y) const {
    return (y - this -> b) / this -> a;
}

Edge::Edge(Vertex *p_1, Vertex *p_2) {
    this -> vertex_1 = p_1;
    this -> vertex_2 = p_2;
    double x_1 = p_1 -> getX();
    double y_1 = p_1 -> getY();
    double x_2 = p_2 -> getX();
    double y_2 = p_2 -> getY();
    this -> a = (y_2 - y_1)/(x_2 - x_1);
    this -> b = y_2 - a * x_2;
}

Vertex *Edge::getVertex1() const {
    return vertex_1;
}

Vertex *Edge::getVertex2() const {
    return vertex_2;
}

bool Edge::operator==(const Edge &rhs) const {
    return vertex_1 == rhs.vertex_1 &&
           vertex_2 == rhs.vertex_2;
}

bool Edge::operator!=(const Edge &rhs) const {
    return !(rhs == *this);
}

double Edge::chargeAlongEdge(vector<Charger *> *chargers, double delta_l, double P_c, double v_bar) const {
    Point* start_point = this->getVertex1();
    double vertex_distance = start_point -> getDistance(this->getVertex2());

    int M = vertex_distance / delta_l;

    double travel_time = delta_l / v_bar;
    double E_max = (P_c - start_point -> chargeToPoint(chargers)) * travel_time;
    for(int i = 0;i < M; ++i){
        double temp_E = 0;
        Point* temp_point;
        for(int j = 0;j < i; ++j){
            if(j == 0){
                //First time move it to the 1/2 delta_l away from start Vertex
                temp_point = this -> moveFromVertex(start_point,delta_l / 2);
            }
            else{
                //Later we can move it one Sigma long each time to next mid-Vertex
                temp_point = this -> moveFromVertex(temp_point, delta_l);
            }
            temp_E += (P_c - temp_point->chargeToPoint(chargers)) * travel_time;
        }
        E_max = temp_E > E_max ? temp_E : E_max;
    }
    return E_max;
}
