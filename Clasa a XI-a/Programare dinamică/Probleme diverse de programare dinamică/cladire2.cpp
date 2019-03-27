#include<fstream>
using namespace std;
ifstream f("cladire2.in");
ofstream g("cladire2.out");
int d = 9901, a[201][201], s[201][201], n, m;

void afisare(int i, int j)
{
    if(i && j)
    {
        if(s[i][j-1] >= s[i-1][j])
            afisare(i, j-1);
        else
            afisare(i-1, j);
        g << i << " " << j << endl;
    }
}



int main()
{
    int i, j;
    f >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            f >> a[i][j];

    for(i = 2; i <= n; i++)
        s[i][1] = a[i][1] + s[i-1][1];
    for(i = 2; i <= m; i++)
        s[1][i] = a[1][i] + s[1][i-1];
    s[1][1] = a[1][1];

    for(i = 2; i <= n; i++)
        for(j = 2; j <= m; j++)
            if(s[i][j-1] >= s[i-1][j])
                s[i][j] = a[i][j] + s[i][j-1];
            else
                s[i][j] = a[i][j] + s[i-1][j];
    g << s[n][m] + a[1][1] << endl;
    afisare(n, m);
    f.close();
    g.close();
    return 0;
}
