#include<fstream>
using namespace std;
ifstream f("cladire.in");
ofstream g("cladire.out");
unsigned long a[1001][1001];


int main()
{
    int n, m, i, j, d = 9901;

    f >> n >> m;
    for(i = 1; i <= n; i++)
        a[i][1] = 1;
    for(i = 1; i <= m; i++)
        a[1][i] = 1;
    for(i = 2; i <= n; i++)
        for(j = 2; j <= m; j++)
            a[i][j] = (a[i-1][j] + a[i][j-1])%d;
    g << a[n][m];
    f.close();
    g.close();
    return 0;
}