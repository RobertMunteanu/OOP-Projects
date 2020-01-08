#pragma once
#include <iostream>
#include <string>

using namespace std;

class personal
{
protected:
	long long cnp;
	string nume;
	string nume_film;
	float procent;
	float incasare; 

public:
	personal() : cnp(NULL),procent(NULL), nume(""), nume_film(""), incasare(NULL) {};
	personal(long long c, float p, string n, string nf, float r) : cnp(c),procent(p), nume(n), nume_film(nf), incasare(r) {};
	personal(const personal& x) : cnp(x.cnp), procent(x.procent), nume(x.nume), nume_film(x.nume_film),incasare(x.incasare) {};

	friend ostream& operator << (ostream& out, const personal& x);
	friend istream& operator >> (istream& in, personal & x);
	personal& operator = (const personal&);

	virtual float salariu() { return 0; }

	~personal() 
	{
		cnp = NULL;
		procent = NULL;
		nume.clear();
		nume_film.clear();
		incasare = NULL; 
	}
};

