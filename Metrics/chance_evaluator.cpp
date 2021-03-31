//
// Created by 朱原昊 on 2021/3/29.
//

#include "chance_evaluator.h"

double ChanceEvaluator::getEvaluationScore() {
    return 0;
}

double ChanceEvaluator::getTruncatedPdfValue(double mu,double sigma) {
    boost::math::normal norm(mu,sigma);
    auto test_value = cdf(complement(norm,0.2));
    return test_value;
}
