//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_CHANCE_EVALUATOR_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_CHANCE_EVALUATOR_H
#include"base_evaluator.h"

class chanceevaluator:public BaseEvaluator{
public:
    double getEvaluationScore() override;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_CHANCE_EVALUATOR_H
