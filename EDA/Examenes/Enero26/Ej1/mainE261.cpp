// Mauro Martinez Montes
// EDA-GDV46

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

using namespace std;

template <class T>
class list_plus : public list<T> {
    using Nodo = typename list<T>::Nodo;

public:
    // Complejidad: lineal O(n)
    list_plus<T> remConsecutiveEq() {
        list_plus<T> res;
        Nodo* act = this->fantasma->sig;

        while (act != this->fantasma) {
            if (act->elem == act->sig->elem) {
                Nodo* orphanNod = desenlanza(act->sig);
                enlanza(orphanNod, res.fantasma->ant);
                res.nelems++;
            }
            else act = act->sig;
        }

        return res;
    }

    void enlanza(Nodo* node, Nodo* nodeRecep) {
        node->ant = nodeRecep;
        node->sig = nodeRecep->sig;
        node->sig->ant = node;
        node->ant->sig = node;
    }

    Nodo* desenlanza(Nodo* node) {
        node->ant->sig = node->sig;
        node->sig->ant = node->ant;
        this->nelems--;
        return node;
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    char e;
    list_plus<char> l, res;

    // leer los datos de la entrada
    cin >> n;
    if (n == -1) return false;
    for (int i = 1; i <= n; ++i) {
        cin >> e;
        l.push_back(e);
    }

    res = l.remConsecutiveEq();

    // Le damos una vuelta para comprobar que la lista está bien formada
    for (int i = 0; i < l.size(); ++i){
        e = l.back();
        l.pop_back();
        l.push_front(e);
    }

    // Ahora imprimimos la lista y de paso la dejamos vacía (tb para probar su consistencia)
    while (!l.empty()){
        cout << l.front() << " ";
        l.pop_front();
    }
    cout << endl;

    // Ahora imprimimos la lista res y de paso la dejamos vacía (tb para probar su consistencia)
    while (!res.empty()){
        cout << res.front() << " ";
        res.pop_front();
    }
    cout << endl;

    return true;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Examenes/Enero26/Ej1/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}