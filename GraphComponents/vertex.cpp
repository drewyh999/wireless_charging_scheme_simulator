//
// Created by Dominique Zhu on 2021/3/21.
//

#include "vertex.h"


Vertex::Vertex(double x, double y) : Point(x, y) {
    degree = 0;
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

void Vertex::setDegree(int degree) {
    Vertex::degree = degree;
}

bool Vertex::comp(Vertex *a, Vertex *b) {
    return a -> degree > b -> degree;
}






