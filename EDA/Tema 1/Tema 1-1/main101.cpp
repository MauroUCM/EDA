// Mauro Martinez Montes
// EDA-GDV46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& datos) {


    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int numVec, aux;

    cin >> numVec;
    if (numVec == 0)
        return false;

    for(int i = 0; i < numVec; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    if (resolver(datos)) cout << "DALTON\n";
    else cout << "DESCONOCIDOS\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 1/Tema 1-1/1.in");
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
