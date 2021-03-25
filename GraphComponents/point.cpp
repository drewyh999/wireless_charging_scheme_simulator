//
// Created by 朱原昊 on 2021/3/22.
//

#include "point.h"

point::point(double x, double y) : x(x), y(y) {}

double point::getX() const {
    return x;
}

void point::setX(double x) {
    point::x = x;
}

double point::getY() const {
    return y;
}

void point::setY(double y) {
    point::y = y;
}

double point::getDistance(point *point) {
    double x_1 = this -> getX();
    double y_1 = this -> getY();
    double x_2 = point -> getX();
    double y_2 = point -> getY();
    return sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
}
