#include "film.h"
#include <cstring>
#include <iostream>

using namespace std; 
//Film constructor


ostream& operator << (ostream& out, const film& film)
{
	out << "Numele filmului este:" << film.nume;
	out << "Tipul filmului este:" << film.tip;
	out << "Filmul are" << film.minute << " minute"; 
	return out;
}
istream& operator >> (istream & in, film & film )
{
	cout << "Introduceti numele filmului: " << endl;
	getline(in, film.nume);
	cout << "Introduceti tipul filmului: " << endl;
	getline(in, film.tip);
	cout << "Introduceti numarul de minute: " << endl;
	in >> film.minute;
	return in;
}
