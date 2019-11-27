#include "Stiva.h"

Stiva::Stiva()
{
	dim = NULL;
	V.reserve(NULL);
}

ostream& operator << (ostream& out, Stiva A)
{
	for (auto i : A.V)
		out << i << endl;
	out << endl;
	return out;
}

istream& operator >> (istream& in, Stiva& A)
{
	int dims;
	cout << "Introduceti numarul de elemente din stiva:  ";
	in >> dims;
	A.setDim(dims);
	for (int i = 0; i < dims; i++)
	{
		Complex AUX;
		in >> AUX;
		A.Push(AUX);
	}
	return in;
}

Stiva Stiva ::operator = (Stiva A)
{
	setDim(A.dim);
	V.clear();
	for (auto i : A.V)
		V.push_back(i);
	return *this;
}

void Stiva::Push(Complex x)
{
	dim++;
	V.insert(V.begin(), x);
}

Complex Stiva::Pop()
{
	Complex AUX;
	AUX = V[0];
	V.erase(V.begin());
	dim--;

	return AUX;
}

Complex Stiva::Peek()
{
	return V[0];
}


bool Stiva::purImaginara()
{
	for (auto i : V)
		if (i.getRe() != 0)
			return false;
		else
			if (i.getIm() == 0)
				return false;

	return true;
		
}

Stiva::~Stiva()
{
	dim = NULL;
	V.clear();
}
