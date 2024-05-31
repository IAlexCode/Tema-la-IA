#ifndef INSTRUMENTE_DE_GENERARE_DATE_EXPERIMENTALE_H
#define INSTRUMENTE_DE_GENERARE_DATE_EXPERIMENTALE_H
#ifndef PREDEFINED_50_CITIES_H
#define PREDEFINED_50_CITIES_H
#ifndef PREDEFINED_10_CITIES_H
#define PREDEFINED_10_CITIES_H
#ifndef EMPTY_CITIES_H
#define EMPTY_CITIES_H
#ifndef EMPTY_ADJ_MATRIX_H
#define EMPTY_ADJ_MATRIX_H

#include <iostream>
#include "StructuraGrafului.h"

extern const vector<string> predefined_50_cities;

extern const vector<string> predefined_10_cities;

extern const vector<string> empty_cities;

extern const vector<vector<int>> empty_adjMatrix;

int randomCost(int min, int max);

vector<vector<int>> generateAdjMatrix(int size);

graph generateData(int size);

void displayGraph(const graph& g);

#endif
#endif
#endif
#endif
#endif
