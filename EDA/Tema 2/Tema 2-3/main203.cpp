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
bool resolver(vector<int>* datos, int iniInd, int finInd, int min, int max) {

    if (iniInd - finInd == 1) return true;

    int midaux = ;

    if(resolver(vector<int>* datos, iniInd, finInd))



    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int size;

    cin >> size;

    if (size == 0)
        return false;

    
    if (resolver(&datos, 0, datos.size(), INT_MIN, INT_MAX)) cout << "SI" << endl;
    else cout << "NO" << endl;

    // escribir sol

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-3/1.in");
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
