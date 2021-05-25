//
// Created by Dominique Zhu on 2021/3/26.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_CHARGER_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_CHARGER_H

#include<cmath>
#include<vector>
#include"coordinate.h"

class Charger : public Coordinate {
private:
    double tau = 0.001;//For the constant in the recharging model
    double Ps;//For the chargers transmit power
    double epsilon = 0.2;//For the small constant that keeps the distance larger than 0
    double dth = 15;
public:
    Charger(double x, double y, double ps);

    double rechargeToDestination(Coordinate *destination);
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_CHARGER_H
