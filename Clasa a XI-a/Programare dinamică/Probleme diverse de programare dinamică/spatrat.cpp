#include<fstream>
#include<iostream>
using namespace std;
ifstream f("spatrat.in");
ofstream g("spatrat.out");
long n, w[401], c[100010], v[100010], m;

int main()
{
    int i, j;
    f >> n;
    for(int i = 1; i <= n; i++)
        c[i] = v[i] = 400;
    for(int i = 1; i*i <= n; i++)
    {
        w[++m] = i * i;
        c[i*i] = 1;
        v[i*i] = i;
        if(2*i*i <= n)
        {
            v[2*i*i] = i;
            c[2*i*i] = 2;
        }
        if(3*i*i <= n)
        {
            v[3*i*i] = i;
            c[3*i*i] = 3;
        }
    }
    for(j = 1; j <= m; j++)
        for(i = 0; i <= n - w[j]; i++)
            if(v[i] < j && i+w[j]== 400 || v[i] < j && c[i] + 1 < c[i+w[j]])
                    {
                v[i+w[j]] = j;
                c[i+w[j]] = c[i] + 1;

                    }


    g << c[n] << endl;
    while(n)
    {
        g << v[n] << " ";
        n -= v[n] * v[n];
    }
    f.close();
    g.close();
    return 0;
}
