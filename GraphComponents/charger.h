//
// Created by 朱原昊 on 2021/3/26.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_CHARGER_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_CHARGER_H

#include<cmath>
#include<vector>
#include"coordinates.h"

class Charger: public Coordinates{
private:
    double tau = 0.003;//For the constant in the recharging model
    double Ps;//For the chargers transmit power
    double epsilon = 0.2316;//For the small constant that keeps the distance larger than 0
    double dth = 15;
public:
    Charger(double x, double y, double ps);

    double rechargeToDestination(Coordinates *destination);

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_CHARGER_H
