#include<fstream>
using namespace std;
ifstream f("hercule.in");
ofstream g("hercule.out");

int a[21][21], n, m, tr, p[21][21];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

void citire()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f >> a[i][j];
    f.close();
}

void bkt(int k, int lin, int col)
{
    if(lin < 1 || col < 1 || lin > n || col > m)
        return;
    if(lin == n && col == m)
    {
        tr = tr + 1;
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            int nlin = lin + di[i];
            int ncol = col + dj[i];
            if(a[nlin][ncol] > k && nlin >= 1 && nlin <= n && ncol >= 1 && ncol <= m && p[nlin][ncol] == 0)
                {   p[nlin][ncol] = 1;
                    bkt(k + 1, nlin, ncol);
                    p[nlin][ncol] = 0;
                }
        }
    }
}

int main()
{
    citire();
    p[1][1] = 1;
    bkt(1, 1, 1);
    g << tr;
    g.close();
    return 0;
}
