// Mauro Martinez Montes
// EDA-GDV46

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;


// Por si queréis imprimir algún vector en depuración
template <class T>
ostream& operator<<(ostream& out, vector<T> const& v){
    for (auto e : v) out << e << " ";
    return out;
}


// función que resuelve el problema
void resolver(... soluc, int k, int n, int h, vector<int> const& puntos, vector<int> const& horas, ..., int& mejorSol) {

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, h;
    cin >> n >> h;
    vector<int> puntos(n);
    vector<int> horas(n);
    for (int i = 0; i < n; ++i) cin >> puntos[i];
    for (int i = 0; i < n; ++i) cin >> horas[i];
    resolver(soluc, k, n, h, puntos, horas, ..., mejorSol);
    cout << mejorSol << endl;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Examenes/Enero26/Ej3/1.in");
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
