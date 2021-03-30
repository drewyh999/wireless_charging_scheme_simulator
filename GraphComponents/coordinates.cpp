//
// Created by 朱原昊 on 2021/3/28.
//

#include "coordinates.h"

coordinates::coordinates(double x, double y) : x(x), y(y) {}

double coordinates::getX() const {
    return x;
}

double coordinates::getY() const {
    return y;
}

double coordinates::getDistance(coordinates *point) const {
    return sqrt(pow(point -> getX() - this -> getX(),2) +
    pow(point -> getY() - this -> getY(),2));
}
