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
bool resolver(vector<int>& datos, int ini, int fin, int& min, int& max) {
    if (fin - ini <= 1) {
        min = max = datos[ini];
        return true;
    }

    int mid = (ini + fin) / 2;
    int minIzq, minDra, maxIzq, maxDra;

    bool ordIzq = resolver(datos, ini, mid, min, max);
    minIzq = min;
    maxIzq = max;

    bool ordDra = resolver(datos, mid, fin, min, max);
    minDra = min;
    maxDra = max;

    min = minIzq;

    return ordDra 
        && ordIzq 
        && maxDra >= maxIzq 
        && minIzq <= minDra;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int aux, min, max;

    cin >> aux;

    if (aux == 0)
        return false;

    cin >> aux;

    while (aux != 0) {
        datos.push_back(aux);
        cin >> aux;
    }
    
    
    if (resolver(datos, 0, datos.size(), min, max)) cout << "SI" << endl;
    else cout << "NO" << endl;

    return true;
}

//int devolverMin() {
//
//}
//
//int devolverMax() {
//
//
//
//}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-3/1.in");
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
