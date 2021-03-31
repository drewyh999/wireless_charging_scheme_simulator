//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_CHANCE_EVALUATOR_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_CHANCE_EVALUATOR_H
#include"base_evaluator.h"
#include"boost/math/distributions/normal.hpp"

class ChanceEvaluator: public BaseEvaluator{
private:
    double pth;
    double delta_l;
    double P_c;
    double v_bar;
    double E_c;


    double getTruncatedPdfValue(double mu,double sigma);
public:
    double getEvaluationScore() override;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_CHANCE_EVALUATOR_H
