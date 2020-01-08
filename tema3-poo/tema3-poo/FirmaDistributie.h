#pragma once
#include "film.h"

template<typename T> 
class FirmaDistributie
{
private:
	int nrTotalPers ;
	int nrActori ;
	vector <film> filmSpecific;
	vector <T> persoane;
public:
	FirmaDistributie() : nrTotalPers(NULL), nrActori(NULL), filmSpecific(NULL, NULL), persoane(NULL, NULL) {};

	FirmaDistributie(const FirmaDistributie&);

	FirmaDistributie& operator=(const FirmaDistributie&);

	~FirmaDistributie()
	{
		nrActori = NULL;
		nrTotalPers = NULL;
		filmSpecific.clear();
		persoane.clear();
	}
};

template <>

class FirmaDistributie <actor>
{
private: 
	int nrPrincipali;
	int nrTotalPers;
	int nrActori;
	vector <film> filmSpecific;
	vector <actor> persoane;
public:
	FirmaDistributie();
	FirmaDistributie(const FirmaDistributie<actor> &);
	FirmaDistributie& operator=(const FirmaDistributie<actor> &);
	friend ostream& operator << (ostream&, FirmaDistributie&);

	~FirmaDistributie()
	{
		nrActori = NULL;
		nrTotalPers = NULL;
		filmSpecific.clear();
		persoane.clear();
	}
};
