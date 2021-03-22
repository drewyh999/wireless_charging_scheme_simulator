//
// Created by 朱原昊 on 2021/3/22.
//

#include "LineFormula.h"

LineFormula::LineFormula(double x_1, double y_1, double x_2, double y_2) {
    this -> a = (y_2 - y_1)/(x_2 - x_1);
    this -> b = y_2 - this -> a * x_2;
}

point* LineFormula::moveFromPoint(double x_start, double y_start, double distance) const {
    double cosine = cos(atan(this -> a));
    double new_x = x_start + distance * cosine;
    double new_y = this -> getYbyX(new_x);
    return new point(new_x, new_y);
}

double LineFormula::getYbyX(double x) const {
    return this -> a * x + this -> b;
}

double LineFormula::getXbyY(double y) const {
    return (y - this -> b) / this -> a;
}
