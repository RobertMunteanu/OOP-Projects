#pragma once
#include "Vector.h"
class Management
{
private:
	vector<Vector> MAN;
	int n;

public:
	Management();

	void setDim(int dim) { n = dim; }
	int getDim() { return n; }
	vector<Vector> getMan() { return MAN; }
	void setMan() { MAN.reserve(NULL); }
	friend ostream & operator << (ostream &, Management);
	friend istream & operator >> (istream &, Management&);
	~Management();
};

