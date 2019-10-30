#ifndef GRAF_H
#define GRAF_H
#include <iostream>

using namespace std;


class Graf
{
    int n,m;
    int **G;
public:
    // setter si getter
        int GetN();
        int** GetG();
        void SetN(int );
        void SetM(int );
        int GetM();
        void SetG( );

        // parcurgeri
        void latime();
        void adancime();
        void adancimeCon(int, int*);
        bool isConex();
        void pondereMin();


    // supraincarcari

        friend istream & operator >> (istream &, Graf &);
        friend ostream & operator << (ostream &, Graf &);
        Graf operator * (const Graf &);
        void operator = (const Graf &);

    // ctr si dctr

        Graf(const Graf &);
        Graf();
        virtual ~Graf();

};

#endif // GRAF_H
