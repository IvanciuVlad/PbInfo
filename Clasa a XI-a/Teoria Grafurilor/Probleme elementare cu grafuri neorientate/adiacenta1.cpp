#include<fstream>
using namespace std;
ifstream f("adiacenta1.in");
ofstream g("adiacenta1.out");
int x, y, a[101][101], i, n, j;

int main()
{
    while(f >> x >> y)
    {
        a[x][y] = 1;
        a[y][x] = 1;
        if(x > n)
            n = x;
        if(y > n)
            n = y;
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
