// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion
// Clase de complejidad
// Cuestion: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"

using namespace std;

// función que resuelve el problema
// Complejidad: n =Tamaño datos, k = tamaño aux, O(n * k)
Set<int> resolver(vector<int> datos, int numMenor) {
    Set<int> aux;

    for (int i : datos) {
        if (aux.size() < numMenor) aux.add(i);
        else if (aux.getMax() > i && !aux.contains(i)) {
            aux.removeMax();
            aux.add(i);
        }
    }

    return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numEl, aux;
    vector<int> datos;

    cin >> numEl >> aux;
    
    if (numEl == 0)
        return false;

    while (aux != -1) {
        datos.push_back(aux);
        cin >> aux;
    }

    // escribir sol
    //cout << datos << " " << datos.getMin() << " " << datos.getMax() << endl;
    cout << resolver(datos, numEl) << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 4/Tema 4-6/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
