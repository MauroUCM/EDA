// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion:
// Clase de complejidad: O(n)
// Cuestion: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolverCaucasico(vector<int>* datos, int ini, int fin, int* pares) {
    if (fin - ini <= 1) {
        if (datos->at(ini) % 2 == 0) {
            (*pares)++;
        }
        return true;
    }

    int mid = (ini + fin) / 2;
    int parIzq = 0,
        parDra = 0;

    bool cauIzq = resolverCaucasico(datos, ini, mid, &parIzq);
    bool cauDra = resolverCaucasico(datos, mid, fin, &parDra);

    *pares = parIzq + parDra;

    return cauIzq && cauDra && abs(parDra - parIzq) <= 2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    vector<int> datos;
    int datosSize, aux;

    // leer los datos de la entrada
    cin >> datosSize;
    if (datosSize == 0)
        return false;

    for (int i = 0; i < datosSize; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    if (resolverCaucasico(&datos, 0, datos.size(), &datosSize)) cout << "SI" << endl;
    else cout << "NO" << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-5/1.in");
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
