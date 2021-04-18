//
// Created by 朱原昊 on 2021/3/28.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_COORDINATE_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_COORDINATE_H
#include<cmath>
#include<string>

class Coordinate {
protected:
    double x;
    double y;
public:

    Coordinate(double x, double y);

    [[nodiscard]] double getX() const;

    [[nodiscard]] double getY() const;

    double getDistance(Coordinate* point) const;

    [[nodiscard]] std::string toString() const;

    bool operator==(const Coordinate &rhs) const;

    void setX(double x);

    void setY(double y);
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_COORDINATE_H
