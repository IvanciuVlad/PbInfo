#include<fstream>
using namespace std;

int n, v[10], s[10];
ifstream f("produscartezian2.in");
ofstream g("produscartezian2.out");

void scrie()
{
    for(int i = 1; i <= n; i++)
        g << s[i] << " ";
    g << endl;
}

void gen(int k)
{
    if(k == n+1)
        scrie();
    else
        for(int i = 1; i <= v[k]; i++)
        {
            s[k] = i;
            gen(k+1);
        }
}

int main()
{
    f >> n;
    for(int i = 1; i <= n; i++)
        f >> v[i];
    f.close();
    gen(1);
    g.close();
    return 0;
}
