#include<fstream>
#include<iostream>
using namespace std;
ifstream f("epuras.in");
ofstream g("epuras.out");
int a[1001][1001], s[1001][1001], n;

int main()
{
    int i, j;
    f >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            f >> a[i][j];
            if((i == n && j == n) || (i == 1 && j == 1))
                continue;
            if(a[i][j] < 0)
                a[i][j] = 0;
        }

    s[1][1] = a[1][1];
    for(i = 2; i <= n; i++)
        s[i][1] = a[i][1] + s[i-1][1];
    for(i = 2; i <= n; i++)
        s[1][i] = a[1][i] + s[1][i-1];

    for(i = 2; i <= n; i++)
        for(j = 2; j <= n; j++)
            if(s[i][j-1] >= s[i-1][j])
                s[i][j] = a[i][j] + s[i][j-1];
            else

                s[i][j] = a[i][j] + s[i-1][j];





    g << s[n][n];
    f.close();
    g.close();
    return 0;
}

