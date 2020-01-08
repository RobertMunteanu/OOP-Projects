#pragma once
#include "personal.h"
class actor : public personal
{
	const float bonus = 0.1;
	bool principal;

public:
	actor() : personal(), principal(false) {};
	actor(long long c, float p, string n,int r, string nf, bool pr) : personal(c, p, n, nf, r), principal(p) {};
	actor(const actor& x) : personal (x), principal(x.principal) {};

	friend ostream& operator << (ostream& out, const actor& x);
	friend istream& operator >> (istream& in, actor& x);
	actor& operator = (const actor&);
	float salariu();


	~actor()
	{
		cnp = NULL;
		procent = NULL;
		nume.clear();
		nume_film.clear();
		principal = NULL;
		incasare = NULL;

	}
};

