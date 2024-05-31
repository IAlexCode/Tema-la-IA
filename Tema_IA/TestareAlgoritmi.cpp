#include "StructuraGrafului.h"
#include "AlgoritmulNearestNeighbor.h"
#include "InstrumenteDeGenerareDateExperimentale.h"
#include "LeastCostSearch.h"
#include <iostream>
#include <chrono>

using namespace std;

void printTour(const vector<int>& tour);

int main() {
    // generare date!
    // graph orase ;
    auto start = chrono::high_resolution_clock::now();
    //nearestNeighbour(orase);
    //tsp_least_cost(orase);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
}

void printTour(const graph& orase, const vector<int>& tour) {
    for (int city : tour) {
        cout << orase.cities[city] << " ";
    }
    cout << endl;
}

int minimumCost(const graph& orase, const vector<int>& tour) {
    int min = 0;
    for (auto it = tour.begin(); it != prev(tour.end()); ++it) {
         min = min + orase.adjMatrix[*it][*next(it)];
    }
    return min;
}
 
// Funcție euristică pentru A* Search, in contextul implementarii mele
// double heuristic(pair<int, int> current, pair<int, int> final) {
    // Distanta euclidiana
  //  return sqrt(pow(final.first - current.first, 2) + pow(final.second - current.second, 2));
// }