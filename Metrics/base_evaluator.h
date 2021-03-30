//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
#include<base_solution.h>

class BaseEvaluator {
protected:
    Solution* solution;
public:
    explicit BaseEvaluator(Solution *solution);

    virtual double getEvaluationScore() = 0;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_EVALUATOR_H
