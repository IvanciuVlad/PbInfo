#include<fstream>
std::ifstream in("roy-floyd.in");
std::ofstream out("roy-floyd.out");
#define INF 10000000

int n, m, c[101][101];


void citire()
{
    int x, y, z, i, j;
    in >> n >> m;
    for(i = 1; i <= m; i++)
    {
        in >> x >> y >> z;
        c[x][y] = z;
    }

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i != j && c[i][j] == 0)
                c[i][j] = INF;
}

void rf()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i != k && j != k && i != j)
                {
                    int t = c[i][k] + c[k][j];
                    if(t < c[i][j])
                        c[i][j] = t;
                }
}

int main()
{
    citire();
    rf();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            if(c[i][j] == INF)
                out << -1 << " ";
            else
                out << c[i][j] << " ";
        out << "\n";
    }
}
