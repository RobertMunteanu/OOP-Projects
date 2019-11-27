#pragma once
#include "Vector.h"
class Coada : public Vector 
{
public:
	Coada();
	Coada(vector<Complex> V, int dim) : Vector(V, dim)
	{

	};
	Coada(const Coada& A) : Vector(A)
	{

	};

	void Push(Complex);
	Complex Pop();
	Complex Peek();
	bool purImaginara();

	friend ostream& operator << (ostream&, Coada);
	friend istream& operator >> (istream&, Coada&);
	Coada operator = (Coada);
	~Coada();

};

