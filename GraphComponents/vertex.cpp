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

vertex::vertex(double x, double y) : point(x, y) {
    this -> next_neighbor = nullptr;
    this -> first_neighbor = nullptr;
}

vertex *vertex::getNextNeighbor() {
    auto result = this -> next_neighbor;
    this -> next_neighbor = this -> next_neighbor -> next_neighbor;
    return result;
}
