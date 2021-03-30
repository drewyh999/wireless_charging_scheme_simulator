//
// Created by 朱原昊 on 2021/3/22.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H
#include<cmath>
#include "charger.h"
#include<vector>
#include "coordinates.h"

class Point : public coordinates{
public:

    Point(double x, double y);

    double chargeToPoint(std::vector<charger*> *chargers);//Without considering the P_c power,recharge to Point only
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H
