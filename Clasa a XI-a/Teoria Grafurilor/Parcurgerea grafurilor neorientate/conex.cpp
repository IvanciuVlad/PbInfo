#include<fstream>
std::ifstream in("conex.in");
std::ofstream out("conex.out");

int n, a[101][101], m, viz[101], ok = 1;

void DFS(int x)
{
    viz[x] = 1;
    for(int i = 1; i <= n; i++)
        if(a[x][i] == 1 && !viz[i])
            DFS(i);
}

int main()
{
    in >> n;
    int x, y;
    while(in >> x >> y)
    {
        if(a[x][y] == 0)
                m++;
        a[x][y] = a[y][x] = 1;
    }
    DFS(1);
    for(int i = 1; i <= n; i++)
        if(!viz[i])
            ok = 0;
    if(ok)
        out << "DA";
    else
        out << "NU";
    in.close();
    out.close();
    return 0;
}
