#include "BreadthFirstSearch.h"


int tsp_bfs(const graph& graph) {
    int start = 0;
    int min_cost = INT_MAX;

    // Coada pentru BFS, elementele sunt perechi de forma (oraș curent, cost parțial)
    queue<pair<int, int>> q;
    q.push({ start, 0 });

    while (!q.empty()) {
        int current = q.front().first;
        int cost = q.front().second;
        q.pop();

        // Dacă am vizitat toate orașele și am ajuns la orașul de plecare
        if (cost != 0 && current == start) {
            min_cost = min(min_cost, cost);
            continue;
        }

        // Pentru fiecare oraș nevizitat, adăugăm următoarea stare în coadă
        for (int next_oras = 0; next_oras < graph.n; ++next_oras) {
            if (next_oras != current) {
                int new_cost = cost + graph.adjMatrix[current][next_oras];
                q.push({ next_oras, new_cost });
            }
        }
    }

    return min_cost;
}