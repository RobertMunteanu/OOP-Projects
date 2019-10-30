#ifndef CITIRE_H
#define CITIRE_H
#include <iostream>
#include "Graf.h"

class Citire
{
private:
    int n;
    Graf *V;
public:
    Citire();
    friend istream & operator >>(istream &, Citire &);
    friend ostream & operator <<(ostream &, Citire &);
    virtual ~Citire();
};

#endif // CITIRE_H
