//
// Created by 朱原昊 on 2021/3/22.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H
#include<cmath>

class point {
protected:
    double x;
    double y;
public:

    point(double x, double y);

    [[nodiscard]] double getX() const;

    void setX(double x);

    [[nodiscard]] double getY() const;

    void setY(double y);

    double getDistance(point* point);
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H
