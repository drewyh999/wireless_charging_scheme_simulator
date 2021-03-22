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
