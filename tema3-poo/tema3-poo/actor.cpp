#include "actor.h"
using namespace std;

ostream& operator << (ostream& out, const actor& x)
{
	out << "CNP: " << x.cnp << endl;
	out << " Nume: " << x.nume << endl;
	out << "Nume film: " << x.nume_film << endl;
	out << "Incasari " << x.incasare << endl;
	out << "Procent: " << x.procent << endl;

	if (x.principal)
		cout << " Actorul este principal";
	else
		cout << " Actorul nu e in rol principal";
	return out;
}
istream& operator >> (istream& in, actor& x)
{
	cout << " Introduceti CNP : " << endl;
	in >> x.cnp;

	cout << "Introduceti Numele : " << endl;
	getline(in, x.nume);

	cout << " Introduceti numele filmului: " << endl;
	getline(in, x.nume_film);

	cout << "Introduceti incasarea: " << endl;
	in >> x.incasare;

	cout << "Introduceti procentul castigat: " << endl;
	in >> x.procent;

	cout << "Este actorul in rol principal? (true /false) \n ";
	in >> x.principal;
	return in;
}

actor& actor ::operator = (const actor& x)
{
	cnp = x.cnp;
	procent = x.procent;
	nume.clear();
	nume.assign(x.nume);
	nume_film.clear();
	nume_film.assign(x.nume_film);
	incasare = x.incasare;
	principal = x.principal;

	return *this;
}
float actor:: salariu()
{
	incasare += bonus * incasare;
	return incasare;
}