//
// Created by Dominique Zhu on 2021/3/21.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_VERTEX_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_VERTEX_H


#include "point.h"
#include<random>
#include "config.h"

class Vertex: public Point {
private:
    //Private property for the truncated normal distribution the stay time is distributed
    double Mu;//The average stay time
    double Sigma; //The standard deviation of the stay time
    int degree;
public:

    Vertex(double x, double y);

    [[nodiscard]] double getMu() const;

    [[nodiscard]] double getSigma() const;

    void setDegree(int degree);

    static bool comp(Vertex *a, Vertex *b);

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_VERTEX_H
