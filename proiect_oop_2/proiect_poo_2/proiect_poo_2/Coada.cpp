#include "Coada.h"

Coada::Coada()
{
	dim = NULL;
	V.reserve(NULL);
}

ostream& operator << (ostream& out, Coada A)
{
	for (auto i : A.V)
		out << i << " ";
	out << endl;
	return out;
}

istream& operator >> (istream& in, Coada& A)
{
	int dimc;
	cout << "Introduceti numarul de elemente din coada:  ";
	in >> dimc;
	A.setDim(dimc);
	for (int i = 0; i < dimc; i++)
	{
		Complex AUX;
		in >> AUX;
		A.Push(AUX);
	}
	return in;
}

Coada Coada ::operator = (Coada A)
{
	setDim(A.dim);
	V.clear();
	for (auto i : A.V)
		V.push_back(i);
	return *this;
}


void Coada::Push(Complex x)
{
	V.push_back(x);
	dim++;
}

Complex Coada::Pop()
{
	Complex AUX;
	AUX = V[0];
	V.erase(V.begin());
	dim--;

	return AUX;
}

Complex Coada::Peek()
{
	return V[0];
}

bool Coada::purImaginara()
{
	for (auto i : V)
		if (i.getRe() != 0)
			return false;
		else
			if (i.getIm() == 0)
				return false;
			else
				return true;

}

Coada::~Coada()
{
	dim = NULL;
	V.clear();
}
