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
void resolver(vector<int>& datos, int& picos, int& valles) {

    for (int p = 1; p < datos.size() - 1; p++)
    {
        if (datos[p - 1] > datos[p] && datos[p + 1] > datos[p])  valles++;
        else if (datos[p - 1] < datos[p] && datos[p + 1] < datos[p])    picos++;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numArr, aux, picos = 0, valles = 0;
    vector<int> datos;

    cin >> numArr;

    for (int i = 0; i < numArr; i++)
    {
        cin >> aux;
        datos.push_back(aux);
    }

    resolver(datos, picos, valles);

    cout << picos << " " << valles << "\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 1/Tema 1-2/1.in");
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