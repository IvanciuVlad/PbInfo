#include<fstream>
using namespace std;
ifstream f("grade.in");
ofstream g("grade.out");
int a[101][101], n;

int main()
{
    f >> n;
    int x, y, i, j, v;
    while(f >> x >> y)
    {
        a[x][y] = a[y][x] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        v = 0;
        for(j = 1; j <= n; j++)
            v += a[i][j];
        g << v << " ";
    }
    f.close();
    g.close();
    return 0;
}
