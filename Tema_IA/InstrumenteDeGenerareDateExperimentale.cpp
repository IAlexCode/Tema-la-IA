#include "InstrumenteDeGenerareDateExperimentale.h"

const vector<string>predefined_50_cities = {
        "Bucuresti", "Cluj-Napoca", "Timisoara", "Iasi", "Constanta",
        "Craiova", "Brasov", "Galati", "Ploiesti", "Oradea",
        "Braila", "Arad", "Pitesti", "Sibiu", "Bacau",
        "Targu Mures", "Baia Mare", "Buzau", "Botosani", "Satu Mare",
        "Ramnicu Valcea", "Suceava", "Drobeta-Turnu Severin", "Focsani", "Bistrita",
        "Tulcea", "Resita", "Slatina", "Calarasi", "Alba Iulia",
        "Giurgiu", "Deva", "Hunedoara", "Zalau", "Sfantu Gheorghe",
        "Barlad", "Turda", "Medias", "Alexandria", "Voluntari",
        "Lugoj", "Roman", "Miercurea Ciuc", "Slobozia", "Sighetu Marmatiei",
        "Mangalia", "Tecuci", "Odorheiu Secuiesc", "Pascani", "Reghin"
};

const vector<string> predefined_10_cities = {
    "Bucuresti", "Cluj-Napoca", "Timisoara", "Iasi", "Constanta",
    "Craiova", "Brasov", "Galati", "Ploiesti", "Oradea"
};

const vector<string> empty_cities = { nullptr };

const vector<vector<int>> empty_adjMatrix(1, vector<int>(1, 0));

int randomCost(int min, int max) {
    return min + rand() % (max - min + 1);
}

vector<vector<int>> generateAdjMatrix(int size) {
    vector<vector<int>> adjMatrix(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i != j) {
                adjMatrix[i][j] = randomCost(1, 100);
            }
        }
    }
    return adjMatrix;
}

graph generateData(int size) {
    if (size == 10) {
        return graph(predefined_10_cities, generateAdjMatrix(10));
    }
    else if (size == 50) {
        return graph(predefined_50_cities, generateAdjMatrix(50));
    }
    else return graph(empty_cities, empty_adjMatrix);
}

void displayGraph(const graph& g) {
    // Afișăm lista de orașe
    cout << "Lista de orase (cities): ";
    for (const auto& city : g.cities) {
        cout << city << " ";
    }
    cout << endl;

    // Afișăm matricea de adiacență
    cout << "Matricea de adiacenta (adjMatrix):" << endl;
    for (const auto& row : g.adjMatrix) {
        for (const auto& cost : row) {
            cout << cost << " ";
        }
        cout << endl;
    }
}