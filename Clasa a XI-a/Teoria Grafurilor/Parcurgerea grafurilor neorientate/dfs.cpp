#include<fstream>
using namespace std;
ifstream in("dfs.in");
ofstream out("dfs.out");
int a[110][110], viz[110], n, m, x, y, z;


void DFS(int x)
{
    viz[x] = 1;
    out << x << " ";
    for(int i = 1; i <= n; i++)
        if(a[x][i] == 1 && !viz[i])
            DFS(i);
}

int main()
{
    in >> n >> m >> x;
    for(int i = 1; i <= m; ++i)
    {
        in >> z >> y;
        a[z][y] = a[y][z] = 1;
    }
    DFS(x);
    in.close();
    out.close();
    return 0;
}
