#ifndef STRUCTURA_GRAFULUI_H
#define STRUCTURA_GRAFULUI_H

#include <vector>
#include <string>
using namespace std;

struct graph {
    graph(const vector<string>& cities, const vector<vector<int>>& adjMatrix) : cities(cities), 
        adjMatrix(adjMatrix), n((int) cities.size()) {}
    vector<string> cities;
    vector<vector<int>> adjMatrix;
    int n;
};

#endif 