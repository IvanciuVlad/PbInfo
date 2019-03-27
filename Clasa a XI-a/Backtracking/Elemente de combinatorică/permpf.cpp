#include<fstream>
using namespace std;

ifstream f("permpf.in");
ofstream g("permpf.out");
int n, s[10], uz[10];

void afisare()
{
    for(int i = 1; i <= n; i++)
        g << s[i] << " ";
    g << endl;
}

void genpermutari(int k)
{
    if(k - 1 == n)
        afisare();
    else
        for(int i = 1; i <= n; i++)
            if(!uz[i] && i != k)
                {
                s[k] = i;
                uz[i] = 1;
                genpermutari(k + 1);
                uz[i] = 0;
                }
}

int main()
{
    f >> n;
    f.close();
    genpermutari(1);
    return 0;
}
