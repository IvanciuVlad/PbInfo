#include<fstream>
using namespace std;
ifstream f("cladire3.in");
ofstream g("cladire3.out");

int a[201][201], s[201][201], n, m;

int main()
{
    int i, j;
    f >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            f >> a[i][j];
    s[n][1] = a[n][1];
    for(i = n-1; i >= 1; i--)
        s[i][1] = a[i][1] + s[i+1][1];
    for(i = 2; i <= m; i++)
        s[n][i] = a[n][i] + s[n][i-1];

    for(i = n-1; i >= 1; i--)
    {
        for(j = 2; j <= m; j++)
            if(s[i+1][j] < s[i][j-1])
                s[i][j] = a[i][j] + s[i+1][j];
            else
                s[i][j] = a[i][j] + s[i][j-1];
    }


    g << s[1][m];
    f.close();
    g.close();
    return 0;
}