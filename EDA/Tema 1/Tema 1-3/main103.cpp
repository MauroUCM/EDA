// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion
// Clase de complejidad: O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& datos, int& cutIndex) {
    int leftMax = datos[0];

    // Buscamos por el numero mas grande hasta la posicion cutIndex inclusive
    for(int p = 0; p <= cutIndex; p++)
    {
        if (datos[p] > leftMax) leftMax = datos[p];
    }

    // Comparamos el maximo del lado izquierdo con los numeros del derecho
    for(int p = cutIndex + 1; p < datos.size(); p++)
    {
        if (datos[p] <= leftMax) return false;
    }

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int cutIndex, arrSize, aux;

    cin >> arrSize;
    cin >> cutIndex;

    for(int i = 0; i < arrSize; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    if (resolver(datos, cutIndex)) cout << "SI\n";
    else cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 1/Tema 1-3/1.in");
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