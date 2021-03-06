//
// Created by Dominique Zhu on 2021/3/22.
//

#include "point.h"


double Point::chargeToPoint(std::vector<Charger *> *chargers) {
    double P_h = 0;
    for(auto & charger : *chargers){
        P_h += charger -> rechargeToDestination(this);
    }
    return P_h;
}

Point::Point(double x, double y) : Coordinate(x, y) {}
