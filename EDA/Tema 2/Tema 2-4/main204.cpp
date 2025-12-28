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
bool resolverDisperso(vector<int>* datos, int* valDis, int ini, int fin) {
    if (fin - ini <= 1) {

        return true;
    }

    int mid = (fin + ini) / 2,
        numDiff = datos->at(ini) - datos->at(fin - 1);

    if (numDiff < 0) {
        numDiff = -numDiff;
    }

    bool resIzq = resolverDisperso(datos, valDis, ini, mid);
    bool resDra = resolverDisperso(datos, valDis, mid, fin);

    return resIzq && resDra && numDiff >= *valDis;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int num, valDis, aux;

    cin >> num;

    if (!std::cin)
        return false;

    cin >> valDis;

    for (int i = 0; i < num; i++) {
        cin >> aux;
        datos.push_back(aux);
    }


    // escribir sol
    if (resolverDisperso(&datos, &valDis, 0, datos.size())) cout << "SI" << endl;
    else cout << "NO" << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-4/1.in");
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