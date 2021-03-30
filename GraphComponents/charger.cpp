//
// Created by 朱原昊 on 2021/3/26.
//

#include "charger.h"

double charger::rechargeToDestination(coordinates *destination) {
    double distance = this -> getDistance(destination);
    if(distance > dth){
        return 0;
    }
    else{
        return (this -> tau * this -> Ps)/pow(this -> dth + this -> epsilon,2);
    }
}

charger::charger(double x, double y, double ps) : coordinates(x, y), Ps(ps) {}

