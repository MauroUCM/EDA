// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion
// Clase de complejidad: O(n)
// Cuestion: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(string w1, string  w2) {
    vector<int> codex;
    codex.resize('z'+ 1);

    for (char i : w1) codex[i]++;
    for (char o : w2) codex[o]--;

    for (char t : codex) if (t != 0) return false;

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string w1, w2;
    cin >> w1 >> w2;


    // escribir sol
    if (resolver(w1, w2)) cout << "SI\n";
    else cout << "NO\n";


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 1/Tema 1-5/1.in");
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