#include "Vector.h"

Vector::Vector()
{
	dim = NULL;
	V.reserve(NULL);
}


ostream & operator << (ostream &out, Vector A)
{
	if (A.V.empty())
		throw "Vectorul nu contine elemente";
	for (auto i : A.V)
		out << i << endl;
	return out;
}

istream& operator >> (istream& in, Vector& A)
{
	int aux;
	cout << " Introduceti dimensiunea vectorului: ";
	in >> aux;
	A.setDim(aux);

	for (int i = 0; i < A.getDim(); i++)
	{
		Complex aux2;
		in >> aux2;
		A.V.push_back(aux2);
	}
	return in;
}

Vector Vector::operator = (Vector A)
{
	setDim(A.getDim());
	V.clear();
	for (auto i : A.V)
		V.push_back(i);
	return *this;
}


Vector::~Vector()
{
	dim = NULL;
	V.clear();
}

