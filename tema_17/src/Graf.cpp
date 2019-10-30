#include "Graf.h"

using namespace std;


Graf::Graf()
{
    n=1;
    m=0;
    G=new int* [1];
    G[0] = new int [1];
}

Graf::Graf(const Graf &A)
{
    n =A.n;
    m=A.m;
    G = A.G;
}

int Graf::GetN()
{
    return n;
}

int Graf::GetM()
{
    return m;
}

void Graf::SetN(int x)
{
    n=x;
}

void Graf::SetM(int z)
{
    m=z;
}

int** Graf::GetG()
{
    return G;
}

void Graf::SetG()
{
    G = new int *[n];
    for(int i=0;i<n;i++)
        G[i] = new int [n];

    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                G[i][j]=0;
}

istream & operator >> (istream &in, Graf &A)
{
    int k,a,b,p,z;
    cout<<"Introduceti numarul de noduri: ";
    in >> k;
    A.SetN(k);

    cout<<"Introduceti numarul de muchii: ";
    in >> z;
    A.SetM(z);

    cout<<"Introduceti coordonatele si ponderea muchiilor: ";
    A.SetG();
    for ( int i=0;i<A.m;i++)
    {
        in >> a >> b >> p;
        A.G[a][b] = p;
        A.G[b][a] = p;
    }
    return in;
}

ostream & operator << (ostream &out, Graf &A)
{

    out<<"Matricea de adiacenta a grafului ponderat este:  "<<endl;
    for (int i=0; i<A.n;i++)
    {
        for(int j=0;j<A.n;j++)
            out<< A.G[i][j] << ' ';
        out<<endl;

    }

    out<<"Lista nodurilor adiacente este:  (pondere) nod  "<<endl;
    for(int i=0; i<A.n; i++)
    {
        out<< "radacina  (" <<i<< ") ";
        for(int j=0; j<A.n; j++)
            if(A.G[i][j] != 0)
                out<< " - " << " (" << A.G[i][j] << ')' << j;
        out <<endl;
    }
    if(A.isConex() == 1)
        cout<<"Graful e conex";
   else
        cout<<"Graful nu e conex";

    return out;
}

int viz (int *V, int n)
{
    for(int i=0; i<n; i++)
        if(V[i] == 0)
            return i;
    return -1;
}

void Graf::latime()
{
    int *C = new int[n], *V = new int[n], comp =0;
    for (int i=0; i<n ;i++)
    {
        C[i] = 0;
        V[i] = 0;
    }
     cout<<endl<<"Parcurgere in latime: "<<endl;
     while (viz(V,n) != -1)
     {
         int ns = viz(V,n);
         int prim, ultim;
         prim = ultim = 0;
         V[ns] = 1;
         C[0] = ns;
         comp++;

         cout<< "Componenta conexa "<< comp << " este formata din nodurile: " << ns << " ";
         while (prim <= ultim)
         {
             for ( int i=0; i<n; i++)
                if( G[C[prim]][i] != 0 && V[i] ==0)
                {
                 ultim++;
                 C[ultim] = i;
                 V[i] = 1;
                 cout<<i<<" ";
                }
                prim++;
         }
         cout << endl;
     }
     delete C;
     delete V;
}

void Graf::adancime()
{
    int *V = new int[n], comp = 0;
    for(int i=0;i<n;i++)
        V[i]=0;
    cout<<endl<<"Parcurgere in adancime: ";
    while (viz(V,n) != -1)
    {
        comp++;
        cout<<endl<<"Componenta conexa " << comp << "este formata din nodurile: ";
        adancimeCon(viz(V,n),V);
    }
    delete V;
}

 void Graf::adancimeCon(int k, int *V)
 {
     V[k]=1;
     cout<<k<<' ';
     for(int i=0 ; i<n; i++)
        if(G[k][i] != 0)
            if(V[i] !=1 )
                adancimeCon(i, V);
 }

 void Graf::operator = (const Graf &A)
 {
     SetN(A.n);
     SetM(A.m);
     SetG();


 }

Graf Graf::operator * (const Graf &A)
{
    int muchii_de_adaugat;
    Graf aux;
    aux.SetN(n);
    aux.SetG();
    for(int i=0; i<n;i++)
        for(int j=0;j<n;j++)
            if (G[i][j] != 0 && A.G[i][j] != 0)
            {
                muchii_de_adaugat++;
                if ( G[i][j] > A.G[i][j])
                    aux.G[i][j] = A.G[i][j];
                else
                    aux.G[i][j] = G[i][j];
            }
    aux.SetM( muchii_de_adaugat /2 );
    return aux;

}
bool Graf::isConex()
{
    int *C = new int[n], *V = new int[n];
    for (int i=0; i<n ;i++)
    {
        C[i] = 0;
        V[i] = 0;
    }
         int ns = viz(V,n);
         int prim, ultim;
         prim = ultim = 0;
         V[ns] = 1;
         C[0] = ns;

         while (prim <= ultim)
         {
             for ( int i=0; i<n; i++)
                if( G[C[prim]][i] != 0 && V[i] ==0)
                {
                 ultim++;
                 C[ultim] = i;
                 V[i] = 1;
                }
                prim++;
         }

     delete C;
     delete V;
     for(int i=0;i< n;i++)
        if(V[i] == 0)
            return false;
     return true;
}

void Graf::pondereMin()
{
    int i,j,k;
    Graf aux;
    aux.SetN(n);
    aux.SetM(m);
    aux.SetG();
    aux.G = G;
    for( k=0;k<n;k++)
        for( i=0;i<n;i++)
            for(  j=0;j<n;j++)
                if(aux.G[i][k] != 0 && aux.G[k][j])
                    if(aux.G[i][j] > aux.G[i][k] + aux.G[k][j])
                        aux.G[i][j] = aux.G[i][k] + aux.G[k][j];
}

Graf::~Graf()
{
    n=0;
    m=0;
    delete G;
}
