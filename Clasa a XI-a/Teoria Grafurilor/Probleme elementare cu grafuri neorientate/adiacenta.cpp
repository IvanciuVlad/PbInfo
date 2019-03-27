#include<fstream>
using namespace std;
ifstream f("adiacenta.in");
ofstream g("adiacenta.out");
int x, y, a[101][101], i, n, j, m;
int main()
{
   
    f >> n >> m;
    for(i = 1; i <= m; i++)
    {
        f >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            g << a[i][j] << " ";
        g << endl;
    }
    f.close();
    g.close();
    return 0;
}
