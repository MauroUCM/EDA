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
char resolver(vector<char> const& datos, char const& primChar, char const& finChar, int ini, int fin) {
    if (fin - ini == 1) {
        if (datos[ini] == finChar) return primChar;
        else return datos[ini] + 1;
    }

    int mid = (ini + fin) / 2;

    if (datos[mid] - datos[ini] == mid - ini) {
        return resolver(datos, primChar, finChar, mid, fin);
    }
    else return resolver(datos, primChar, finChar, ini, mid);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<char> datos;
    char ini, fin, aux;
    cin >> ini >> fin;

    for (int i = 0; i < fin - ini; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    cout << resolver(datos, ini, fin, 0, datos.size()) << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-11/1.in");
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