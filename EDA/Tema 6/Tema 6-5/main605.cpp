// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion: El codigo va escalando el arbol recogiendo los maximos y minimos
//                          mientras comprueba si se cumplen los requisitos para cada raiz.
// Clase de complejidad: Lineal, O(n), n siendo el número de de elementos del arbol.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

bool resuelve(bintree<int> tree, int min, int max) {
    if (tree.empty()) return true;

    if (resuelve(tree.left(), min, tree.root())) {
        if (resuelve(tree.right(), tree.root(), max)) {
            return tree.root() > min && tree.root() < max;
        }
    }
   
    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    bintree<int> tree = leerArbol(int(-1));
    
    if (resuelve(tree, INT_MIN, INT_MAX)) cout << "SI" << endl;
    else cout << "NO" << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 6/Tema 6-5/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int i;
    cin >> i;

    for (int u = 0; u < i; u++) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
