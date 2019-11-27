#include "Management.h"
#include "Stiva.h"
#include "Coada.h"


Management::Management()
{
	n = NULL;
	setMan();
}

istream& operator >> (istream& in, Management &A)
{
	int aux;
	cout << "Introduceti dimensiunea: ";
	in >> aux;
	A.setDim(aux);

	cout << "Pentru stiva -> tasta 1 / Pentru coada -> tasta 2" << endl;
	for (int i = 0; i < A.getDim(); i++)
	{
		int com;
		cout << "Ce fel de structura vrei sa adaugi? :";
		in >> com;
		switch (com)
		{
		case 1:
		{
			Stiva AUXS;
			in >> AUXS;
			A.getMan().push_back(AUXS);
			break;
		}

		case 2:
		{
			Coada AUXC;
			in >> AUXC;
			A.getMan().push_back(AUXC);
			break;
		}
		}
	}
	return in;
}


ostream& operator << (ostream& out, Management A)
{
	for (auto i : A.getMan())
	{
		out << i;
		out << endl;
	}
	return out;
}

Management ::~Management()
{
	

	n = NULL;
	for (auto i : getMan())
	{
		i.setDim(NULL);
		i.getVec().clear();
	}

}