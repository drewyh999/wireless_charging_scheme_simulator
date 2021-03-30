//
// Created by 朱原昊 on 2021/3/22.
//

#include "point.h"


double Point::chargeToPoint(std::vector<charger *> *chargers) {
    double P_h = 0;
    for(auto & charger : *chargers){
        P_h = charger -> rechargeToDestination(this) + P_h;
    }
    return P_h;
}

Point::Point(double x, double y) : coordinates(x, y) {}
