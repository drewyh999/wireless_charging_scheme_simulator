//
// Created by 朱原昊 on 2021/4/20.
//

#include "utils.h"

void utils::printProgress(double percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

vector<double> utils::chargerToCoordinateVector(vector<Charger *> *placement) {
    vector<double> result;
    for (auto *charger : *placement) {
        result.push_back(charger->getX());
        result.push_back(charger->getY());
    }
    return result;
}

vector<Charger *> *utils::coordinateVectorToCharger(vector<double> vec, double Ps) {
    auto result = new vector<Charger *>();
    int i = 0;
    while (i < vec.size()) {
        result->push_back(new Charger(vec[i], vec[i + 1], Ps));
        i += 2;
    }
    return result;
}
