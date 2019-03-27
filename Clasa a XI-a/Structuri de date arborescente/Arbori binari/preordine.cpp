#include<fstream>
std::ifstream in("preordine.in");
std::ofstream out("preordine.out");
int n, r, st[1001], dr[1001], v[1001], t[1001];

void citire()
{
    in >> n;
    for(int i = 1; i <= n; i++)
        in >> v[i] >> st[i] >> dr[i];

}

void vsd(int x)
{
    if(x)
    {
        out << v[x] << " ";
        vsd(st[x]);
        vsd(dr[x]);
    }
}


int main()
{
    citire();
    for(int i = 1; i <= n; i++)
    {
        t[st[i]] = i;
        t[dr[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        if(!t[i])
            r = i;
    vsd(r);
}
