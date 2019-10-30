#include "Citire.h"

using namespace std;

Citire::Citire()
{
    n = 0;
    V = NULL;
}

ostream & operator << (ostream &out, Citire &X)
{
    for (int i=0; i<X.n; i++)
    {
        out << endl << "Graful cu numarul " << i+1 << ':' << endl;
        out << X.V[i] << endl;
        out << "---------------------------------------------------";
    }
    return out;
}

istream & operator >> (istream &in, Citire &X)
{
    int aux;
    Graf Aux;
    cout << "Introduceti numarul de Grafuri: ";
    in >> aux;
    X.n = aux;
    X.V = new Graf[X.n];

    for (int i=0; i<X.n; i++)
    {
        cout << "Introduceti graful cu numarul " << i+1 << endl;
        in >> Aux;
        X.V[i] = Aux;
    }
    return in;
}

Citire::~Citire()
{
    //dtor
}
