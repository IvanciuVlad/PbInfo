#include<fstream>
#include<iostream>
using namespace std;

ifstream f("nrsubsircresc.in");
ofstream g("nrsubsircresc.out");
int n, v[301];
unsigned long long int s = 0, c[301];

int main()
{
    int i, j;
    f >> n;
    for(i = 1; i <= n; i++)
        f >> v[i];
    c[n] = 1;
    for(i = n-1; i >= 1; i--)
    {
        c[i] = 1;
        for(j = i+1; j <= n; j++)
            if(v[i] < v[j])
                c[i] += c[j];
    }

    for(i = 1; i <= n; i++)
        s += c[i];


    g << s;
    f.close();
    g.close();
    return 0;
}
