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
int resuelvePerfilConcavo(vector<int>* datos, int ini, int fin) {
    // caso base
    if (fin - ini == 1) {
        return datos->at(ini);
    }

    int mid = (ini + fin) / 2;

    if (datos->at(mid - 1) < datos->at(mid)) {  // deducir en que lado esta el minimo
        return resuelvePerfilConcavo(datos, ini, mid);
    }
    else {
        return resuelvePerfilConcavo(datos, mid, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int vecSiz, aux;
    vector<int> datos;

    cin >> vecSiz;
    
    if (!std::cin)
        return false;

    for (int i = 0; i < vecSiz; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    cout << resuelvePerfilConcavo(&datos, 0, vecSiz) << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-7/1.in");
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