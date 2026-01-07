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
void resolverNumeroFeliz(Set<int>& datos, int candidato) {
   
    cout << candidato << " ";

    if (candidato == 1) {
        cout << "1";
    }
    else if (datos.contains(candidato)) {
        cout << "0";
    }
    else {
        datos.add(candidato);

        int newCandidato = 0,
            aux;
        while (candidato != 0) {
            aux = candidato % 10;
            newCandidato += aux*aux;
            candidato = (candidato - aux) / 10;
        }
        resolverNumeroFeliz(datos, newCandidato);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numFel;
    Set<int> resultado;

    cin >> numFel;

    if (!std::cin)
        return false;


    // escribir sol
    resolverNumeroFeliz(resultado, numFel);

    cout << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 4/Tema 4-1/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}