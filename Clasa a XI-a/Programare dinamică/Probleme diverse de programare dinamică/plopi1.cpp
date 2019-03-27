#include<fstream>
#include<iostream>
using namespace std;

ifstream f("plopi1.in");
ofstream g("plopi1.out");
int n, v[1001], lmax, l[1001];

int main()
{
    int i, j, pmax;
    f >> n;
    for(i = 1; i <= n; i++)
        f >> v[i];
    l[n] = 1;
    for(i = n-1; i >= 1; i--)
    {
        lmax = 0;
        for(j = i+1; j <= n; j++)
            if(v[i] > v[j] && lmax < l[j])
                lmax = l[j];
        l[i] = lmax + 1;
    }
    lmax = l[1];
    pmax = 1;
    for(i = 2; i <= n; i++)
    {
        if(l[i] > lmax)
        {
            lmax = l[i];
            pmax = i;
        }
    }

    g << n - lmax;
    f.close();
    g.close();
    return 0;
}
