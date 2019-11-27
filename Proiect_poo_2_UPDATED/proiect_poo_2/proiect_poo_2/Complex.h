#pragma once
#include <iostream>

using namespace std;

class Complex
{
private:
	float im;
	float re;
public:
	////////////CTR///////////
	Complex();
	Complex(float im, float re) : im(im), re(re) {};
	Complex(const Complex &x) : Complex(x.im, x.re) {};

	//////////GetsiSet////////
	float getRe();
	float getIm();
	void setRe(float);
	void setIm(float);
	bool isNull();

	/////////Operatori////////
	friend ostream & operator << (ostream &, Complex );
	friend istream & operator >> (istream &, Complex &);
	Complex operator = (Complex);
	Complex operator + (Complex);
	Complex operator - (Complex);
	Complex operator * (Complex);

	///////////DCTR///////////
	~Complex();
};

