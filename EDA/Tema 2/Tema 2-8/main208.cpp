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


bool estaEnIzq(int ini, int mid, int fin) {
    if (ini < mid) {
        return true;
    }

    return true;
}
// función que resuelve el problema
int resolverMinimoRotado(vector<int>* datos, int ini, int fin) {
    int mid = (ini + fin) / 2,
        iniNum = datos->at(ini),
        finNum = datos->at(fin - 1),
        midNum = datos->at(mid);

    if (fin - ini <= 2) {
        if (iniNum > finNum) return finNum;
        else return iniNum;
    }

    if (iniNum < midNum)
    {
        return resolverMinimoRotado(datos, ini, mid + 1);
    }
    else
    {
        return resolverMinimoRotado(datos, mid, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int vecSize, aux;
    vector<int> datos;
    
    cin >> vecSize;

    if (!std::cin)
        return false;

    for (int i = 0; i < vecSize; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    cout << resolverMinimoRotado(&datos, 0, datos.size()) << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-8/1.in");
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