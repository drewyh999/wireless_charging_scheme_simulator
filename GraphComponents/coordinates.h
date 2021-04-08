//
// Created by 朱原昊 on 2021/3/28.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_COORDINATES_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_COORDINATES_H
#include<cmath>
#include<string>

class Coordinates {
protected:
    double x;
    double y;
public:

    Coordinates(double x, double y);

    [[nodiscard]] double getX() const;

    [[nodiscard]] double getY() const;

    double getDistance(Coordinates* point) const;

    [[nodiscard]] std::string toString() const;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_COORDINATES_H
