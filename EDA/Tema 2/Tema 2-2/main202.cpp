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
int digitoComp(int digito) {
    return 9 - digito;
}

int comp(int n) {
    if (n <= 9) return digitoComp(n);   // caso base
    int compResto = comp(n / 10);
    return compResto * 10 + (digitoComp(n % 10));
}

int compInv(int n, int acu) {
    if (n <= 9) return acu * 10 + digitoComp(n);
    else {
        return compInv(n / 10, 10 * acu + digitoComp(n % 10));
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int datos;
    cin >> datos;



    // escribir sol
    cout << comp(datos) << " " << compInv(datos, 0) << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 2/Tema 2-2/1.in");
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