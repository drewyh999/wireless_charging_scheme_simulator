//
// Created by 朱原昊 on 2021/3/22.
//

#include "LineFormula.h"



point* LineFormula::moveFromPoint(point* start_point, double distance) const {
    double cosine = cos(atan(this -> a));
    double new_x = start_point -> getX() + distance * cosine;
    double new_y = this -> getYbyX(new_x);
    return new point(new_x, new_y);
}

double LineFormula::getYbyX(double x) const {
    return this -> a * x + this -> b;
}

double LineFormula::getXbyY(double y) const {
    return (y - this -> b) / this -> a;
}

LineFormula::LineFormula(point *p_1, point *p_2) {
    double x_1 = p_1 -> getX();
    double y_1 = p_1 -> getY();
    double x_2 = p_2 -> getX();
    double y_2 = p_2 -> getY();
    this -> a = (y_2 - y_1)/(x_2 - x_1);
    this -> b = y_2 - a * x_2;
}
