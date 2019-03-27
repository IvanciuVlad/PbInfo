#include<fstream>
using namespace std;
int n, m, c[16];
ifstream f("combinari.in");
ofstream g("combinari.out");

void Afisare()
{
    for(int i = 1; i <= m; i++)
        g << c[i] << " ";
    g << endl;
}

void GenCombinari(int k)
{
    if(k-1 == m)
        Afisare();
    else
        for(int i = c[k-1]+1; i <= n - m + k; i++)
    {
        c[k] = i;
        GenCombinari(k + 1);
    }
}

int main()
{
    f >> n >> m;
    GenCombinari(1);
    f.close();
    g.close();
    return 0;
}
