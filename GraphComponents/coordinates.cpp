//
// Created by 朱原昊 on 2021/3/28.
//

#include "coordinates.h"

Coordinates::Coordinates(double x, double y) : x(x), y(y) {}

double Coordinates::getX() const {
    return x;
}

double Coordinates::getY() const {
    return y;
}

double Coordinates::getDistance(Coordinates *point) const {
    return sqrt(pow(point -> getX() - this -> getX(),2) +
    pow(point -> getY() - this -> getY(),2));
}

std::string Coordinates::toString() const {
    return std::to_string(x) + std::string(",") +std::to_string(y);
}
