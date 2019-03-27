#include<fstream>
#include<iostream>
using namespace std;
ifstream in("subgraf1.in");
ofstream out("subgraf1.out");
int a[101][101], n, m, g[101], mi = 100;

int main()
{
    int x, y;
    in >> n;
    while(in >> x >> y)
    {
        a[x][y] = a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            g[i] += a[i][j];
        if(g[i] < mi)
            mi = g[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(g[i] == mi)
            for(int j = 1; j <= n; j++)
                a[i][j] = a[j][i] = 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            m += a[i][j];
    /*cout << mi << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }*/
    out << m/2;;
    in.close();
    out.close();
    return 0;
}
