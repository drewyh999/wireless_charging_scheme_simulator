//
// Created by 朱原昊 on 2021/3/22.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_EDGE_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_EDGE_H
#include<cmath>
#include "point.h"
#include "vertex.h"
#include<vector>

using namespace std;

class Edge {
    //For a line in the x-y coordinate system, it is generally expressed as y = ax + b

private:
    double a; //For a

    double b; //For b

    Point* point_1;

    Point* point_2;
public:
    [[nodiscard]] double getYbyX(double x) const;

    [[nodiscard]] double getXbyY(double y) const;

    Edge(Point* p_1, Point* p_2);//Construct the line by two Point coordinate of
                                                                // the vertices

    [[nodiscard]] Point *getPoint1() const;

    [[nodiscard]] Point *getPoint2() const;

    bool operator==(const Edge &rhs) const;

    bool operator!=(const Edge &rhs) const;

    double chargeAlongEdge(vector<charger *> *chargers, double delta_l, double P_c, double v_bar) const;
private:
    [[nodiscard]] Point* moveFromPoint(Point* start_point, double distance) const;//Calculate the coordinate for the x_start & y_start
    //after moving for distance on the line direction
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_EDGE_H
