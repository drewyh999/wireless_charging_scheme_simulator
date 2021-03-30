//
// Created by 朱原昊 on 2021/3/22.
//

#include "edge.h"



Point* Edge::moveFromPoint(Point* start_point, double distance) const {
    double cosine = cos(atan(this -> a));
    double new_x = start_point -> getX() + distance * cosine;
    double new_y = this -> getYbyX(new_x);
    return new Point(0, 0);
}

double Edge::getYbyX(double x) const {
    return this -> a * x + this -> b;
}

double Edge::getXbyY(double y) const {
    return (y - this -> b) / this -> a;
}

Edge::Edge(Point *p_1, Point *p_2) {
    this -> point_1 = p_1;
    this -> point_2 = p_2;
    double x_1 = p_1 -> getX();
    double y_1 = p_1 -> getY();
    double x_2 = p_2 -> getX();
    double y_2 = p_2 -> getY();
    this -> a = (y_2 - y_1)/(x_2 - x_1);
    this -> b = y_2 - a * x_2;
}

Point *Edge::getPoint1() const {
    return point_1;
}

Point *Edge::getPoint2() const {
    return point_2;
}

bool Edge::operator==(const Edge &rhs) const {
    return point_1 == rhs.point_1 &&
           point_2 == rhs.point_2;
}

bool Edge::operator!=(const Edge &rhs) const {
    return !(rhs == *this);
}

double Edge::chargeAlongEdge(vector<charger *> *chargers, double delta_l, double P_c, double v_bar) const {
    Point* start_point = this -> getPoint1();
    double vertex_distance = start_point -> getDistance(this -> getPoint2());

    int M = vertex_distance / delta_l;

    double travel_time = delta_l / v_bar;
    double E_max = (P_c - start_point->chargeToPoint(chargers)) * travel_time;
    for(int i = 0;i < M; ++i){
        double temp_E = 0;
        for(int j = 0;j < i; ++j){
            Point* temp_point;
            if(j == 0){
                //First time move it to the 1/2 delta_l away from start Point
                temp_point = this -> moveFromPoint(start_point,delta_l / 2);
            }
            else{
                //Later we can move it one Sigma long each time to next mid-Point
                temp_point = this -> moveFromPoint(temp_point, delta_l);
            }
            temp_E += (P_c - temp_point->chargeToPoint(chargers)) * travel_time;
        }
        if(temp_E > E_max){
            E_max = temp_E;
        }
    }
    return E_max;
}
