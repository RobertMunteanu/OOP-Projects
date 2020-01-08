#pragma once
#include "personal.h"	
class regizor:public personal	
{
	float sumaFixa;


public:
	regizor() : personal(),sumaFixa(NULL) {};
	regizor(long long c, float p, string n, int r, string nf, bool pr,float suma) : personal(c, p, n, nf, r),sumaFixa(suma) {};
	regizor(const regizor& x) : personal(x), sumaFixa(x.sumaFixa) {};

	friend ostream& operator << (ostream& out, const regizor& x);
	friend istream& operator >> (istream& in, regizor& x);
	regizor& operator = (const regizor&);

	float salariu();

	~regizor()
	{
		cnp = NULL;
		procent = NULL;
		nume.clear();
		nume_film.clear();
		incasare = NULL;
		sumaFixa = NULL;

	}
};

