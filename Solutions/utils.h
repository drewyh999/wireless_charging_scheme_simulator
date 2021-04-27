//
// Created by 朱原昊 on 2021/4/20.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_UTILS_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_UTILS_H

#include "config.h"
#include <iostream>
#include "charger.h"
#include <vector>
#include "chance_evaluator.h"
#include "energy_evaluator.h"
#include "power_evaluator.h"

using namespace std;

class utils {
public:
    static void printProgress(double percentage);

    static vector<double> chargerToCoordinateVector(vector<Charger *> *placement);

    static vector<Charger *> *coordinateVectorToCharger(vector<double> vec, double Ps);

    static double getEvaluationSum(vector<Charger *> *charger_placement, ChanceEvaluator *chance_evaluator,
                                   EnergyEvaluator *energy_evaluator, PowerEvaluator *power_evaluator);

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_UTILS_H
