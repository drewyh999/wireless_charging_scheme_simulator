//
// Created by 朱原昊 on 2021/3/21.
//

#include "vertex.h"


Vertex::Vertex(double x, double y) : Point(x, y) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(MU_RANGE_LOW, MU_RANGE_HIGH);
    Mu = dist(mt);
    Sigma = Mu / 2;
}

double Vertex::getMu() const {
    return Mu;
}

double Vertex::getSigma() const {
    return Sigma;
}


