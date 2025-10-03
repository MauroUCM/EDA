// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion:
// Clase de complejidad:
// Cuestion: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int buscaImpar(vector<int> const& datos, int ini, int fin) {
    int n = fin - ini;
    if (n == 1) return datos[ini];

    int mid = (ini + fin) / 2;
    if (datos[mid] % 2 == 1) return datos[mid];
    

    return 5872;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int vecSiz, aux;
    cin >> vecSiz;

    if (vecSiz == 0)
        return false;

    vector<int> datos;
    for(int i = 0; i < vecSiz; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    cout << buscaImpar(datos, 0, vecSiz) << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-10/1.in");
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
