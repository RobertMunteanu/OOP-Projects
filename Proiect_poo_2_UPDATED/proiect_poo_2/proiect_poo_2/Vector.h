#pragma once
using namespace std;
#include "Complex.h"
#include <vector>
class Vector
{
protected:
	vector<Complex> V;
	int dim;
public:

	//////////////Constructor/////////////
	Vector();
	Vector(vector < Complex > V, int dim) : V(V), dim(dim) {};
	Vector(const Vector& x) : V(x.V), dim(x.dim) {};
	//////////// SET si GET ///////////

	int getDim () 
	{
		return dim;
	}

	void setDim(int x)
	{
		dim = x;
	}
	vector<Complex> getVec() { return V; }
	////////////////Operatori///////////////
	friend ostream& operator << (ostream&, Vector);
	friend istream& operator >> (istream&, Vector&);
	Vector operator = (Vector);

	virtual bool purImaginara() { return true; };

	//////////////////// Destructor ///////////////
	~Vector();
};

