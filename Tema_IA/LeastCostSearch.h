#ifndef LEAST_COST_SEARCH_H
#define LEAST_COST_SEARCH_H

#include "StructuraGrafului.h"
#include <queue>
#include <vector>

struct Node {
    int oras;
    int cost;
    vector<int> path;

    Node(int oras, int cost, const vector<int>& path) : oras(oras), cost(cost), path(path) {}

    // Suprascriem operatorul '<' pentru a folosi nodurile în coada de priorități
    bool operator<(const Node& other) const {
        return cost > other.cost; // Sortăm crescător după cost
    }
};

vector<int> tsp_least_cost(const graph& g);

#endif
