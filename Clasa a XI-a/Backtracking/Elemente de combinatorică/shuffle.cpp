#include <iostream>
#include <fstream>
using namespace std;

int v[12], multime[12], cnt;

ifstream f("shuffle.in");
ofstream g("shuffle.out");




///verific daca ceea ce este pana la nivelul k, inclusiv e corect <=>
///verific daca pe poz k am pus corect
bool valideaza(int k, int n)
{
    register int i;
    for(i = 1; i < k; ++i)
        if(v[i] == v[k] )
            return false;

    int j;

    for(i = 1; i <= n; i++)
        if(multime[i] == v[k])
            j = i;

    /// j = poz in multimea initiala a elementului
    if(j != 1 && j != n)
    {
        if(multime[j-1] == v[k-1] || multime[j+1] == v[k-1] )
            return false;
    }

    if(j == 1)
    {
        if(multime[j+1] == v[k - 1])
            return false;
    }

    if(j == n)
    {
        if(multime[j-1] == v[k - 1])
            return false;
    }


    return true;
}

void afiseaza(int n)
{
    for(int i = 1; i <= n; ++i)
        g << v[i] << ' ';
    g << '\n';
    ++cnt;
}

void back(int k, int n)
{
    if(k == n + 1)
        afiseaza( n );
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            v[k] = i;
            if(valideaza(k,n) == true)
                back(k + 1, n);
            ///cand ma intorc din recursivitate
            v[k] = 0;
        }
    }
}


int main()
{
    int n, k,i;
    f >> n;
    for(i = 1; i <= n; i++)
        f>>multime[i];


        k = 1;
    back(k, n);

    if(cnt == 0)
        g<<"nu exista";

    f.close();
    g.close();

    return 0;
}
