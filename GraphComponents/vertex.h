//
// Created by 朱原昊 on 2021/3/21.
//

#ifndef WIRELESS_CHARGING_SCHEME_SIMULATOR_VERTEX_H
#define WIRELESS_CHARGING_SCHEME_SIMULATOR_VERTEX_H


#include "point.h"

class vertex: public point {
private:
    vertex *first_neighbor;
    vertex *next_neighbor;
public:

    vertex(double x, double y, vertex *firstNeighbor);

    [[nodiscard]] vertex *getNextNeighbor() const;

    void AddNextNeighbor(vertex *newNeighbor);

    void resetNeighborPointer();

    vertex* getNextEdge();

};


#endif //WIRELESS_CHARGING_SCHEME_SIMULATOR_VERTEX_H
