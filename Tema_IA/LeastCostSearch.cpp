#include "LeastCostSearch.h"

vector<int> tsp_least_cost(const graph& orase) {
    int start = 0;
    int min_cost = INT_MAX;
    vector<int> best_path;

    // Coada de priorități pentru noduri (oraș, cost)
    priority_queue<Node> pq;
    pq.push(Node(start, 0, { start }));

    while (!pq.empty()) {
        int current = pq.top().oras;
        int cost = pq.top().cost;
        vector<int> path = pq.top().path; // Extragem calea parcursă până la nodul curent
        pq.pop();

        // Dacă am vizitat toate orașele și am ajuns la orașul de plecare
        if (cost != 0 && current == start) {
            if (cost < min_cost) {
                min_cost = cost;
                best_path = path;
            }
            continue;
        }

        // Pentru fiecare oraș nevizitat, adăugăm următoarea stare în coada de priorități
        for (int next_oras = 0; next_oras < orase.n; ++next_oras) {
            if (next_oras != current) {
                int new_cost = cost + orase.adjMatrix[current][next_oras];
                vector<int> new_path = path;
                new_path.push_back(next_oras); // Adăugăm orașul curent în cale
                pq.push(Node(next_oras, new_cost, new_path));
            }
        }
    }

    return best_path;
}
