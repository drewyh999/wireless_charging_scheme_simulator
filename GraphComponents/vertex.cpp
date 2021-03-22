//
// Created by 朱原昊 on 2021/3/21.
//

#include "vertex.h"


void vertex::AddNextNeighbor(vertex *newNeighbor) {
    if(this -> first_neighbor == nullptr){
        this -> first_neighbor = newNeighbor;
    }
    while(this -> next_neighbor != nullptr){
        this -> next_neighbor = this -> next_neighbor -> next_neighbor;
    }
    this -> next_neighbor = newNeighbor;
}

void vertex::resetNeighborPointer() {
    this -> next_neighbor = this -> first_neighbor;
}

vertex *vertex::getNextEdge() {
    return nullptr;
}

vertex::vertex(double x, double y, vertex *firstNeighbor) : point(x, y), first_neighbor(firstNeighbor) {
    this -> next_neighbor = firstNeighbor;
}

vertex *vertex::getNextNeighbor() const {
    return nullptr;
}
