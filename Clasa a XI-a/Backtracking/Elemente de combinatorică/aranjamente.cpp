#include<fstream>
using namespace std;

int f[10], uz[10], n, m;
ifstream in("aranjamente.in");
ofstream g("aranjamente.out");

void afisare()
{
    for(int i = 1; i <= m; i++)
        g << f[i] << " ";
    g << endl;
}

void GenAranjamente(int k)
{
    if(k-1 == m)
        afisare();
    else
        for(int i = 1; i <= n; i++)
            if(!uz[i])
    {
        f[k] = i;
        uz[i] = 1;
        GenAranjamente(k+1);
        uz[i] = 0;
    }
}



int main()
{
    in >> n >> m;
    in.close();
    GenAranjamente(1);
    g.close();
    return 0;
}
