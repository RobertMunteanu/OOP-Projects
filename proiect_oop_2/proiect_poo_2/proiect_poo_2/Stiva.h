#pragma once
#include "Vector.h"
class Stiva : public Vector
{
public:
	Stiva();
	Stiva(vector<Complex> V, int dim) : Vector(V, dim)
	{

	};
	Stiva(const Stiva& A) : Vector(A)
	{

	};

	////////////// Functii stiva //////////

	void Push(Complex);
	Complex Pop();
	Complex Peek();
	bool purImaginara();

	friend ostream& operator << (ostream&, Stiva);
	friend istream& operator >> (istream&, Stiva &);
	Stiva operator = (Stiva);


	~Stiva();
};

