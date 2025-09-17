// Mauro Martinez Montes
// EDA-GDV46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> datos) {
    vector<int> sol;

    for (int p : datos) sol.push_back(p * 2);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada    
    int numVec, aux;
    vector<int> datos;

    cin >> numVec;
    if (numVec == -1)
        return false;

    for (int i = 0; i < numVec; i++)
    {
        cin >> aux;
        datos.push_back(aux);
    }


    vector<int> sol = resolver(datos);
    // escribir sol
    for (int num : sol) cout << num << " ";
    cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 0/Tema 0-6/1.in");
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
