//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_ENERGY_EVALUATOR_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_ENERGY_EVALUATOR_H
#include "base_evaluator.h"

class energy_evaluator:public BaseEvaluator{
private:
    double E_B;
public:
    energy_evaluator(Solution *solution, double eB);

    double getEvaluationScore() override;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_ENERGY_EVALUATOR_H
