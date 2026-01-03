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
int resolver(vector<int> const& datos, int ini, int fin) {
    if (fin - ini <= 2) {

    }

    int mid = (fin + ini) / 2;

    if (mid % 2 == 0) { // par
        if (datos[mid] == datos[mid + 1]) return resolver(datos, mid, fin);
        else return resolver(datos, ini, mid + 1);
    }
    else {  // impar
        if (datos[mid] == datos[mid - 1]) return resolver(datos, mid, fin);
        else return resolver(datos, ini, mid);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int numCasos, aux;

    cin >> numCasos;

    for (int i = 0; i < numCasos; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    cout << resolver(datos, 0, datos.size()) << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-13/1.in");
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