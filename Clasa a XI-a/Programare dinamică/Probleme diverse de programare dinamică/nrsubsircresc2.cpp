#include<iostream>
#include<fstream>
using namespace std;

#define dim 1002

ifstream in("nrsubsircresc2.in");
ofstream out("nrsubsircresc2.out");

long long sol[dim][dim]; /* sol[k][i] = nr. de subsiruri strict crescatoare de lungime k care au ultimul element v[i]*/
long long v[dim];
long long n,p;



void add_subsiruri(int from, int to)
{
    int k;

    k=1;
    while(k<n  &&  sol[k][from] > 0) /// (obs) Daca 'from' nu poate forma un subsir de lungime 5, implicit nu va forma subsiruri de dimensiune 6, 7, 8,...
    {
        sol[k+1][to] += sol[k][from]; /// adaug v[to] la 'k' subsiruri existente
        ++k;
    }
}

int main()
{
    long long i,j,s;

    in>>n>>p;
    for(i=0; i<n; ++i) in>>v[i];

    for(i=0; i<n; ++i)
    {
        sol[1][i] = 1;
        for(j=0; j<i; ++j)
            if(v[i] > v[j]) /// daca v[i] este mai mare decat un predecesor de-al sau
                add_subsiruri(j, i); /// va prelua toate subsirurile (lungime 1, 2, .., n)
    }

    s=0;
    for(i=0; i<n; ++i) s += sol[p][i];

    out<<s<<"\n";

    return 0;
}