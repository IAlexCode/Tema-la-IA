#include "AlgoritmulNearestNeighbor.h"

vector<int> nearestNeighbour(const graph& orase, int i = -1) {
	vector<bool> visited(orase.n, false);
	vector<int> tour;
    int start;
    if (i == -1) 
        start = rand() % orase.n;
    else
        start = i;
    tour.push_back(start);
    visited[start] = true;
    int current = start, nextCity;

    for (int i = 1; i < orase.n; ++i) {
        int minDistance = numeric_limits<int>::max();

        for (int j = 0; j < orase.n; ++j) {
            if (!visited[j] && orase.adjMatrix[current][j] < minDistance) {
                nextCity = j;
                minDistance = orase.adjMatrix[current][j];
            }
        }

        tour.push_back(nextCity);
        visited[nextCity] = true;
        current = nextCity;
    }

    tour.push_back(start);
    return tour;
}

bool sameHamiltonianCycleFromAllNodes(const graph& orase) {
    // Ob?ine ciclurile Hamiltoniene pornind din fiecare nod de pornire
    vector<vector<int>> cycles;
    for (int i = 0; i < orase.n; ++i) {
        vector<int> cycle = nearestNeighbour(orase, i);
        cycles.push_back(cycle);
    }

    // Verific? dac? toate ciclurile sunt identice
    for (int i = 1; i < orase.n; ++i) {
        if (cycles[i] != cycles[0]) {
            return false;
        }
    }
    return true;
}