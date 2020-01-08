#include "FirmaDistributie.h"

template <typename T>
FirmaDistributie <T> ::FirmaDistributie(const FirmaDistributie& aux)
{
	nrActori = aux.nrActori;
	nrTotalPers = aux.nrTotalPers;
	filmSpecific.clear();
	for (int i = 0; i < aux.filmSpecific.size(); i++)
	{
		filmSpecific.push_back(aux.filmSpecific[i]);
	}
	persoane.clear();
	for (int i = 0; i < aux.persoane.size(); i++)
	{
		persoane.push_back(aux.persoane[i]);
	}
}

template <typename T>
FirmaDistributie<T>& FirmaDistributie<T> :: operator = (const FirmaDistributie<T>& aux)
{
	nrActori = aux.nrActori;
	nrTotalPers = aux.nrTotalPers;
	filmSpecific.clear();
	for (int i = 0; i < aux.filmSpecific.size(); i++)
	{
		filmSpecific.push_back(aux.filmSpecific[i]);
	}
	persoane.clear();
	for (int i = 0; i < aux.persoane.size(); i++)
	{
		persoane.push_back(aux.persoane[i]);
	}
	return *this;
}

FirmaDistributie<actor>::FirmaDistributie()
{
	nrPrincipali = NULL;
	nrTotalPers = NULL;
	nrActori = NULL;
	filmSpecific.reserve(NULL);
	persoane.reserve(NULL);
}

FirmaDistributie<actor>::FirmaDistributie(const FirmaDistributie<actor> &aux)
{
	nrPrincipali = aux.nrPrincipali;
	nrActori = aux.nrActori;
	nrTotalPers = aux.nrTotalPers;
	filmSpecific.clear();
	for (int i = 0; i < aux.filmSpecific.size(); i++)
	{
		filmSpecific.push_back(aux.filmSpecific[i]);
	}
	persoane.clear();
	for (int i = 0; i < aux.persoane.size(); i++)
	{
		persoane.push_back(aux.persoane[i]);
	}
}

FirmaDistributie<actor>& FirmaDistributie<actor> :: operator = (const FirmaDistributie<actor>& aux)
{
	nrPrincipali = aux.nrPrincipali;
	nrActori = aux.nrActori;
	nrTotalPers = aux.nrTotalPers;
	filmSpecific.clear();
	for (int i = 0; i < aux.filmSpecific.size(); i++)
	{
		filmSpecific.push_back(aux.filmSpecific[i]);
	}
	persoane.clear();
	for (int i = 0; i < aux.persoane.size(); i++)
	{
		persoane.push_back(aux.persoane[i]);
	}
	return *this;
}

template<typename T> 
ostream& operator << (ostream& out, FirmaDistributie<T>& x)
{
	out << "Numarul total de persoane implicate este: " << x.nrTotalPers<<endl;
	out << " Numarul total de actori este: " << x.nrActori << endl;
	out << "Persoanele implicate sunt: " << endl;
	for (auto i : x.persoane)
		out << i;
	out << "Filmele sunt: " << endl;

	for (auto i : x.filmSpecific)
		out << i;
	return out;
	
}

ostream& operator << (ostream& out, FirmaDistributie<actor>& x)
{
	out << "Numarul total de persoane implicate este: " << x.nrTotalPers << endl;
	out << " Numarul total de actori este: " << x.nrActori << endl;
	out << "Numarul de actori principali este" << x.nrPrincipali<<endl;
	out << "Persoanele implicate sunt: " << endl;
	for (auto i : x.persoane)
		out << i;
	out << "Filmele sunt: " << endl;

	for (auto i : x.filmSpecific)
		out << i;
	return out;
}