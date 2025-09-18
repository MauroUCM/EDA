// Mauro Martinez Montes
// EDA-GDV46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(vector<int>& datos) {
    for (int& u : datos)u = u * 2;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int numVec, aux;

    cin >> numVec;

    if (!std::cin)
        return false;

    for (int p = 0; p < numVec; p++) {
        cin >> aux;
        datos.push_back(aux);
    }

    resolver(datos);

    // escribir sol
    for (int i : datos) cout << i << " ";
    cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 0/Tema 0-7/1.in");
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