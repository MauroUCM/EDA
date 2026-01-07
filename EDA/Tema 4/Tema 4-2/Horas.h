//  Implementación del TAD Set con array dinámico ordenado y sin repeticiones

#ifndef HORA_H
#define HORA_H

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Hora {
protected:
	int hor = 0, 
        min = 0, 
        sec = 0;


public:
    friend ostream& operator<<(ostream& out, Hora const& hora);
    friend istream& operator>>(istream&, Hora& hora);
    friend bool operator<(Hora const& propia, Hora const& ajena);

    Hora() {}


protected:

};

//ostream& operator<<(ostream& out, Set<T> const& set) {
//    for (int i = 0; i < set.nelems - 1; i++)
//        out << set.array[i] << " ";
//    if (set.nelems > 0) out << set.array[set.nelems - 1];
//    return out;
//}

ostream& operator<<(ostream& out, Hora const& hora) {
    out << hora.hor << ":" << hora.min << ":" << hora.sec;
    return out;
}

istream& operator>>(istream& in, Hora& hora) {
    in >> hora.hor;
    in.ignore();
    in >> hora.min;
    in.ignore();
    in >> hora.sec;

    return in;
}

bool operator<(Hora const& propia, Hora const& ajena){
    if (propia.hor < ajena.hor) {
        return true;
    }


}


#endif //HORA_H
