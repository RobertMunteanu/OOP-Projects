#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "actor.h"
using namespace std;
class film
{
private:
	string nume;
	string tip;
	int minute;
	
public:
	film() : nume(""), tip(""), minute(NULL) {};
	film(string n, string t, int m) : nume(n), tip(t), minute(m) {};
	film(const film& film) : nume(film.nume), tip(film.tip), minute(film.minute) {};
	friend ostream & operator << ( ostream & out, const film &film);
	friend istream & operator >> ( istream & in, film& film);
	~film()
	{
		nume.clear();
		tip.clear();
		minute = NULL;
	}

};

