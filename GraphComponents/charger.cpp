//
// Created by 朱原昊 on 2021/3/26.
//

#include "charger.h"

double Charger::rechargeToDestination(Coordinate *destination) {
    double distance = this -> getDistance(destination);
    if(distance > dth){
        return 0;
    }
    else{
        return (tau * Ps)/pow(epsilon + distance,2);
    }
}

Charger::Charger(double x, double y, double ps) : Coordinate(x, y), Ps(ps) {}

