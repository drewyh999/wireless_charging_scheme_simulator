//
// Created by 朱原昊 on 2021/3/29.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H

#include<iostream>
class Solution {
protected:
    Graph *graph;
    vector<charger*> *charger_placement;
public:

    Solution(Graph *graph, vector<charger *> *chargerPlacement);

    [[nodiscard]] Graph *getGraph() const;

    [[nodiscard]] vector<charger *> *getChargerPlacement() const;
};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_BASE_SOLUTION_H
