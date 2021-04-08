//
// Created by 朱原昊 on 2021/3/26.
//

#include "charger.h"

double Charger::rechargeToDestination(Coordinates *destination) {
    double distance = this -> getDistance(destination);
    if(distance > dth){
        return 0;
    }
    else{
        return (this -> tau * this -> Ps)/pow(this -> dth + this -> epsilon,2);
    }
}

Charger::Charger(double x, double y, double ps) : Coordinates(x, y), Ps(ps) {}

