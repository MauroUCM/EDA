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
bool resolver(vector<int>& datos, int& numBuscado, int ini, int fin) {
    int mid = (ini + fin) / 2,
        iniNum = datos[ini],
        midNum = datos[mid],
        finNum = datos[fin - 1];

    if (fin - ini == 1) {
        if (datos[ini] == numBuscado) return true;
        else return false;
    }

    if (midNum > iniNum) {  // corte en la derecha
        if (numBuscado >= iniNum && numBuscado < midNum) 
            return resolver(datos, numBuscado, ini, mid);
        else return resolver(datos, numBuscado, mid, fin);
    }
    else {  // corte en la izquierda
        if (numBuscado >= midNum && numBuscado <= finNum) 
            return resolver(datos, numBuscado, mid, fin);
        else return resolver(datos, numBuscado, ini, mid);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int vecSize, numBuscado, aux;

    cin >> vecSize;

    if (vecSize == -1)
        return false;

    cin >> numBuscado;
    for (int i = 0; i < vecSize; i++) {
        cin >> aux;
        datos.push_back(aux);
    }
    
    // escribir sol
    if (resolver(datos, numBuscado, 0, datos.size())) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-9/1.in");
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
