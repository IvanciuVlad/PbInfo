#include<fstream>
using namespace std;
ifstream f("bila.in");
ofstream g("bila.out");

int n, m, is, js, a[21][21], kmax;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void citire()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f >> a[i][j];
    f >> is >> js;
    f.close();
}

void bkt(int k, int lin, int col)
{
    if(lin == 1 || col == 1 || lin == n || col == m)
    {
        if(k > kmax)
            kmax = k;
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            int nlin = lin + di[i];
            int ncol = col + dj[i];
            if(a[nlin][ncol] < a[lin][col])
                bkt(k+1, nlin, ncol);
        }
    }
}

int main()
{
    citire();
    bkt(1, is, js);
    g << kmax;
    g.close();
}
