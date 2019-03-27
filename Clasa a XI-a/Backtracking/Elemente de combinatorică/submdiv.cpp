#include<fstream>
using namespace std;
ifstream f("submdiv.in");
ofstream g("submdiv.out");

int n, d[100], s[100], uz[100], x, m, ok;

void Afisare()
{
    for(int i = 1; i <= m; i++)
        g << d[s[i]] << " ";
    g << endl;
}

void GenCombinari(int k)

{

    if(k-1 == m)
        Afisare(), ok = 1;
    else
        for(int i = s[k-1]+1; i <= n - m + k; i++)
        {
            s[k] = i;
            GenCombinari(k + 1);
        }
}

int main()
{
    f >> x >> m;
    int i, j = 1;
    for(i = 1; i <= (x/2)+1; i++)
        if(x%i == 0)
            d[j] = i, j++;
    d[j] = x;
    n = j;
    GenCombinari(1);
    if(ok == 0)
        g << "fara solutie";
    g.close();
    f.close();
    return 0;
}
