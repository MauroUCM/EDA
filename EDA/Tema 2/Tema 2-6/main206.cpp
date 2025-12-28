// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion
// Clase de complejidad
// Cuestion: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool elemento_situado(const vector<int>* datos, int ini, int fin) {
    if (fin - ini == 1) {
        if (datos->at(ini) == ini)
        {
            return true;
        }
        else return false;
    }
    else if (fin - ini <= 0) {
        return false;
    }

    int mid = (ini + fin) / 2;

    return elemento_situado(datos, ini, mid) || elemento_situado(datos, mid, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int sizeDatos, aux;

    cin >> sizeDatos;

    for (int i = 0; i < sizeDatos; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    if (elemento_situado(&datos, 0, datos.size())) cout << "SI\n";
    else cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-6/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}