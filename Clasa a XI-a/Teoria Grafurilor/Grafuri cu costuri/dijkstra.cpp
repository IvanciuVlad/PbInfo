#include <iostream>
#include <fstream>
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
int c[101][101],n,p,d[101],v[101],t[101];
int INF = int(1e9);
void citire()
{
    in >> n >> p;
    int x,y,z;
    while(in >> x >> y >> z)
    {
        c[x][y] = z;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if( i!= j && c[i][j] == 0)
                c[i][j] = INF;
}
void raspuns()
{
    for(int i = 1; i <= n; ++i)
        if(d[i] < INF)
            out << d[i] << " ";
        else
            out << "-1 ";
}
void djkstra(int r)
{
    int i,j;
    for(int i = 1; i <= n; ++i)
    {
        d[i] = c[r][i];
        if(d[i] < INF && i != r)
            t[i] = r;
    }
    v[r] = 1;
    for(i = 1; i <= n-1; ++i)
    {
        int dmin = INF , pos;
        for(j = 1; j <= n; ++j)
        {
            if(v[j] == 0)
            {
                if(d[j] < dmin)
                {
                    dmin = d[j];
                    pos = j;
                }
            }
        }
        if(dmin == INF)
                break;
        v[pos] = 1;
        for(j = 1; j <= n; ++j)
        {
            if(v[j] == 0)
            {
                if(d[pos] + c[pos][j] < d[j])
                {
                    d[j] = d[pos] + c[pos][j];
                    t[j] = pos;
                }
            }

        }

    }
}

int main()
{
    citire();
    djkstra(p);
    raspuns();
    return 0;
}
