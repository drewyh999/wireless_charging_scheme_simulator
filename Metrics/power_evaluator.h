//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_POWER_EVALUATOR_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_POWER_EVALUATOR_H
#include"base_evaluator.h"

class PowerEvaluator: public BaseEvaluator{
private:
    double P_c;
public:
    PowerEvaluator(Solution *solution, double pC);

    double getEvaluationScore() override;

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_POWER_EVALUATOR_H
