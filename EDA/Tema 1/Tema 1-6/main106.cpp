// Mauro Martinez Montes
// EDA-GDV46

// Resumen de la solucion:
// Clase de complejidad: O(n)
// Cuestion: El menor orden de complejidad posible es el O(n * log(n)), ya que el ordenamiento en si tiene un mayor
// orden que la comparación de listados O(n).

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void comparaListados(vector<char> const& eda, vector<char> const& tpv,
    vector<char>& comunes, vector<char>& soloEda, vector<char>& soloTpv) {

    int edaSize = eda.size() - 1, tpvSize = tpv.size() - 1, contEda = 0, contTpv = 0;
    char minVec, maxVec;

    if(edaSize >= 0 && tpvSize >= 0)
    {
        // sacamos maximos y minimos
        if (eda[0] > tpv[0]) minVec = tpv[0];
        else minVec = eda[0];
        if (eda[edaSize] > tpv[tpvSize]) maxVec = eda[edaSize];
        else maxVec = tpv[tpvSize];

        //comprobamos los posibles
        for (char i = minVec; i <= maxVec; i++)
        {
            bool EdaHas = false, TpvHas = false;

            // revisamos ambas listas hasta que encontremos la letra o nos la adelantemos
            if (contEda <= edaSize) {
                while (eda[contEda] < i && contEda <= edaSize) contEda++;
                if (eda[contEda] == i) {
                    EdaHas = true;
                    contEda++;
                }
            }

            if (contTpv <= tpvSize) {
                while (tpv[contTpv] < i && contTpv < tpvSize) contTpv++;
                if (tpv[contTpv] == i) {
                    TpvHas = true;
                    contTpv++;
                }
            }


            if (EdaHas && TpvHas)   comunes.push_back(i);
            if (EdaHas && !TpvHas)  soloEda.push_back(i);
            if (!EdaHas && TpvHas)  soloTpv.push_back(i);
        }
    }
    else if(edaSize < 0)
    {
        soloTpv = tpv;
    }
    else if(tpvSize < 0)
    {
        soloEda = eda;
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
    comparaListados(eda,tpv,comunes,soloEda,soloTpv);
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
    std::ifstream in("Tema 1/Tema 1-6/1.in");
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
