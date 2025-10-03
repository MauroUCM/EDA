/*
Nombre completo: Mauro Martínez Montes
DNI: 05942835A
Usuario del juez: EDA-GDV46
Qué has conseguido hacer y qué no: Todo lo que se pedia.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Complejidad: log2(fin - ini) 


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int buscarAumento(vector<int> const& datos, int obj, int ini, int fin) {
    int n = fin - ini;
    if (n == 1) {
        if (datos[ini] - datos[ini - 1] == obj) return ini;
        else return -1;
    }

    int mid = (fin + ini) / 2;
    if (datos[mid] - datos[mid - 1] <= obj) return buscarAumento(datos, obj, mid, fin);
    else return buscarAumento(datos, obj, ini, mid);
}

void resuelveCaso() {
    // leer los datos de la entrada
    int size, inc;
    cin >> inc >> size;
    vector<int> sec(size);
    for (int& e : sec) cin >> e;
    
    // Llamada a función y escritura de la salida
    if (inc == 0) cout << "0\n";
    else cout << buscarAumento(sec, inc, 1, size) << "\n";
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-15/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
