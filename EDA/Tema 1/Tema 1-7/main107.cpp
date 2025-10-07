
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void comparaListados(vector<char> const& eda, vector<char> const& tpv,
    vector<char>& comunes, vector<char>& soloEda, vector<char>& soloTpv) {
    
    vector<int> codex;
    int codSiz = 'z' - 'a' + 1, pijasp = 'z' - 'a';

    codex.resize(codSiz);

    for (int i = 0; i < tpv.size(); i++) {
        codex[tpv[i] - 'a'] += 1;
    }

    for (int o = 0; o < eda.size(); o++) {
        codex[eda[o] - 'a'] += 2;
    }

    for (int p = 0; p < codex.size(); p++) {
        if (codex[p] == 1) soloTpv.push_back('a' + p);
        else if (codex[p] == 2) soloEda.push_back('a' + p);
        else if (codex[p] == 3) comunes.push_back('a' + p);
    }



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<char> eda(n);
    vector<char> comunes;
    vector<char> soloEda;
    vector<char> soloTpv;
    for (char& e : eda) cin >> e;
    cin >> n;
    vector<char> tpv(n);
    for (char& e : tpv) cin >> e;
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);
    for (char& e : comunes) cout << e << " ";
    cout << endl;
    for (char& e : soloEda) cout << e << " ";
    cout << endl;
    for (char& e : soloTpv) cout << e << " ";
    cout << endl;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Tema 1/Tema 1-7/1.in");
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
