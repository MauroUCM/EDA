// Mauro Martinez Montes
// EDA-GDV46

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
	// Complejidad:
    void reordena() {
        Nodo* currentNode = this->prim;

        while (currentNode->sig != nullptr) {
            if (currentNode->elem > currentNode->sig->elem) {
                relocateNextFirst(currentNode);
            }
            else currentNode = currentNode->sig;
        }
        this->ult = currentNode;
    }

    void relocateNextFirst(Nodo* node) {
        Nodo* aux = node->sig;
        node->sig = node->sig->sig;
        aux->sig = this->prim;
        this->prim = aux;
    }
};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, e;
    queue_plus<int> q;
    std::cin >> n;
    if (n == 0) return false;
    for (int i = 0; i < n; ++i) {
        std::cin
 >> e;
        q.push(e);
    }

    q.reordena();

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i){
        n = q.front();
        q.pop();
        q.push(n);
    }

    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()){
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Examenes/Junio25/Ej1/1.in");
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