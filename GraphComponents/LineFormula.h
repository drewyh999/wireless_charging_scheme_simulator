//
// Created by 朱原昊 on 2021/3/22.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_LINEFORMULA_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_LINEFORMULA_H
#include<cmath>
#include "point.h"

class LineFormula {
    //For a line in the x-y coordinate system, it is generally expressed as y = ax + b
public:
    double a; //For a

    double b; //For b

    [[nodiscard]] double getYbyX(double x) const;

    [[nodiscard]] double getXbyY(double y) const;

    LineFormula(point* p_1,point* p_2);//Construct the line by two point coordinate of
                                                                // the vertices
    [[nodiscard]] point* moveFromPoint(point* start_point, double distance) const;//Calculate the coordinate for the x_start & y_start
                                                                        //after moving for distance on the line direction
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_LINEFORMULA_H
