// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion
// Clase de complejidad
// Cuestion: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Horas.h"

using namespace std;

// función que resuelve el problema
bool resolver(vector<Hora> const& horasGuar, Hora const& horasPreg, int candidato) {
    if (candidato == horasGuar.size()) {
        return false;
    }
    else {


        resolver(horasGuar, horasPreg, candidato + 1);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numHor, numPreg;

    cin >> numHor >> numPreg;

    if (numHor == 0 && numPreg == 0)
        return false;

    vector<Hora> horasGuar, horasPreg;
    Hora aux;

    for (int i = 0; i < numHor; i++) {
        cin >> aux;
        horasGuar.push_back(aux);
    }
    for (int o = 0; o < numPreg; o++) {
        cin >> aux;
        if (!resolver(horasGuar, aux, 0)) cout << "ERROR\n";
    }

    // escribir sol
    

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 4/Tema 4-2/1.in");
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
