#include<fstream>
#include<iostream>
using namespace std;
ifstream f("subgraf.in");
ofstream g("subgraf.out");

int n, m, a[101][101];

int eprim(int x)
{
    if(x <= 1)
        return 0;
    if(x == 2)
        return 1;
    for(int i = 2; i*i <= x; i++)
        if(x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int x, y;
    f >> n;
    while(f >> x >> y)
    {
        if(!eprim(x) && !eprim(y))
            a[x][y] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j])
                m++;
    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << m;*/
    g << m;
    f.close();
    g.close();
    return 0;
}
