#include<fstream>
std::ifstream in("componenteconexe.in");
std::ofstream out("componenteconexe.out");

int n, a[101][101], m, nrc, viz[101];

void DFS(int x, int o)
{
    viz[x] = o;
    for(int i = 1; i <= n; i++)
        if(a[x][i] == 1 && !viz[i])
            DFS(i, o);
}

int main()
{
    int x, y;
    in >> n;
    while(in >> x >> y)
    {
        if(!a[x][y])
            m++;
        a[x][y] = a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!viz[i])
            {
                nrc++;
                DFS(i, nrc);
            }
    }
    out << nrc << "\n";
    for(int i = 1; i <= nrc; i++)
    {
        for(int j = 1; j <= n; j++)
                if(viz[j] == i)
                    out << j << " ";
        out << "\n";;
    }
    in.close();
    out.close();
    return 0;
}
