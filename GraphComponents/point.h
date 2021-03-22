//
// Created by 朱原昊 on 2021/3/22.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H


class point {
public:
    double x;
    double y;

    point(double x, double y);

    [[nodiscard]] double getX() const;

    void setX(double x);

    [[nodiscard]] double getY() const;

    void setY(double y);
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_POINT_H
