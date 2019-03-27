#include<fstream>
std::ifstream in("postordine.in");
std::ofstream out("postordine.out");
int n, r, st[1001], dr[1001], v[1001], t[1001];

void citire()
{
    in >> n;
    for(int i = 1; i <= n; i++)
        in >> v[i] >> st[i] >> dr[i];

}

void sdv(int x)
{
    if(x)
    {
        sdv(st[x]);
        sdv(dr[x]);
        out << v[x] << " ";

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
    sdv(r);
}
