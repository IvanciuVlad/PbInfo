#include<fstream>
using namespace std;
ifstream f("produs_matrice.in");
ofstream g("produs_matrice.out");
int n, m, p, a[101][101], b[101][101]; 
long long c[101][101];


int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f >> a[i][j];
    f >> p;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= p; j++)
            f >> b[i][j];

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= p; ++j)
        {
            c[i][j] = 0;
            for(int k = 1; k <= m; ++k)
                c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
            g << c[i][j] <<" ";
        }
        g << endl;
    }



    f.close();
    g.close();
    return 0;
}