#include<fstream>
using namespace std;
ifstream f("sumtri.in");
ofstream g("sumtri.out");
int n, a[101][101], s[101][101];

void citire()
{
    f >> n;
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= i; j++)
            f >> a[i][j];
}

int main()
{
    citire();
    int i, j;
    for(i = 1; i <= n; i++)
        s[n][i] = a[n][i];
    for(i = n-1; i >= 1; i--)
        for(j = 1; j <= i; j++)
            s[i][j] = a[i][j] + max(s[i+1][j], s[i+1][j+1]);
    g << s[1][1];
    f.close();
    g.close();
    return 0;
}
