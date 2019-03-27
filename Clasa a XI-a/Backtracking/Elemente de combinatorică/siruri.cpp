#include<fstream>
using namespace std;
ifstream f("siruri.in");
ofstream g("siruri.out");
int n, m, s[16];

void afisare()
{
    for(int i = 1; i <= m; i++)
        g << s[i] << " ";
    g << endl;
}

int verf(int k, int j)
{
    int i;
    s[k] = j;
    for(i = 2; i <= k; i++)
        if(s[i] - s[i-1] > 2)
            return 0;
    return 1;


}

void gen(int k)
{
    if(k-1 == m)
            afisare();
        else
            for(int i = s[k-1] + 1; i <= n - m + k; i++)
                if(verf(k, i))
            {
                s[k] = i;
                gen(k + 1);
            }
}

int main()
{
    f >> n >> m;
    gen(1);
    f.close();
    g.close();
    return 0;
}
