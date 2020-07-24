//Pokolorowanie wierzchołków grafu nazywamy legalnym, jeśli dwa jego połączone wierzchołki mają różny kolor.
//Najmniejsza liczba kolorów (mogą być wszystkie odcienie różowego) potrzebnych do (legalnego) pokolorowania grafu to liczba chromatyczna tego grafu.
//Stopień wierzchołka jest to liczba wychodzących z niego krawędzi.
//
//Sprawdź czy liczba chromatyczna grafu jest większa niż jego największy stopień.
//
//Wejście
//        W pierwszej linii liczba kolejnych linii. W następnych liniach. Liczba wierzchołków grafu, a następnie po spacji macierz sąsiedztwa grafu G (wypisana od lewej do prawej z góry na dół bez spacji).
//Wyjście
//        True, jeśli liczba chromatyczna grafu jest większa niż jego największy stopień. False, w przeciwnym przypadku.

#include<iostream>
#include<string>

using namespace std;


bool check_if_odd_cycle(int vertex) {
    return vertex % 2 == 1;
}


bool check_if_cycle_graph(int vertex, char **matrix) {
    for (int i=0; i<vertex; i++) {
        int counter = 0;
        for (int j=0; j<vertex; j++) {
            if (matrix[i][j] == '1') counter++;
        }
        if (counter == 2) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}


bool check_if_complete_graph(int vertex, char **matrix) {
    for (int i=0; i<vertex; i++) {
        for (int j=0; j<vertex; j++) {
            if (i==j) {
                if (matrix[i][j] != '0') {
                    return false;
                }
            }
            else {
                if (matrix[i][j] != '1') {
                    return false;
                }
            }
        }
    }
    return true;
}


void create_adjacency_matrix() {
    int vertex;
    string entry_graph;
    cin >> vertex >> entry_graph;

    char **matrix = new char *[vertex];

    for (int i = 0; i < vertex; i++) {
        matrix[i] = new char[vertex]; // Tworzymy wiersze
    }

    // wypełniamy macierz zerami
    int counter = 0;
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            matrix[i][j] = entry_graph[counter];
            counter++;
        }
    }

    if (check_if_complete_graph(vertex, matrix) || (check_if_odd_cycle(vertex) && check_if_cycle_graph(vertex, matrix))) {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }

    for (int i = 0; i < vertex; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

}


int main() {
    int number_of_graphs;
    cin >> number_of_graphs;

    for (int i=0; i<number_of_graphs; i++) {
        create_adjacency_matrix();
    }

    return 0;
}