//
// Created by 朱原昊 on 2021/3/28.
//

#include "coordinate.h"

Coordinate::Coordinate(double x, double y) : x(x), y(y) {}

double Coordinate::getX() const {
    return x;
}

double Coordinate::getY() const {
    return y;
}

double Coordinate::getDistance(Coordinate *point) const {
    return sqrt(pow(point -> getX() - this -> getX(),2) +
    pow(point -> getY() - this -> getY(),2));
}

std::string Coordinate::toString() const {
    return std::to_string(x) + std::string(",") +std::to_string(y);
}

bool Coordinate::operator==(const Coordinate &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}


