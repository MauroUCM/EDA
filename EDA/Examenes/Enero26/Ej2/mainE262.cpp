/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no: 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// Complejidad:
int calcularFlota(bintree<int> const& a, const int& capacidad, int& barcos) {
    if (a.empty()) {
        return 0;
    }
 
    int espLibre = calcularFlota(a.right(), capacidad, barcos) + calcularFlota(a.left(), capacidad, barcos);

    while (espLibre < a.root()) {
        barcos++;
        espLibre += capacidad;
    }

    espLibre -= a.root();

    return espLibre;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arch;
    int capacidad;
    arch = leerArbol(-1);
    cin >> capacidad;
    int barcos = 0,
    espacio = calcularFlota(arch, capacidad, barcos);
    cout << barcos << " " << espacio << endl;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("Examenes/Enero26/Ej2/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
