#include<fstream>
using namespace std;
ifstream f("sirpie.in");
ofstream g("sirpie.out");
int n, s[15], v[15], uz[15];


void afisare()
{
    for(int i = 1; i <= n; i++)
        g << s[i] << " ";
    g << endl;
}

int valid(int k)
{
    if(k == 1)
        return 1;
    int a = s[k];
    int b = s[k-1];
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
             b -= a;
    }
    if(a == 1)
        return 1;

    return 0;
}


void genpermutari(int k)
{
    if(k-1 == n)
        afisare();
    else
        for(int i = 1; i <= n; i++)
            if(!uz[i])
    {
        s[k] = v[i];
        uz[i] = 1;
        if(valid(k))
            genpermutari(k + 1);
        uz[i] = 0;
    }
}

int divide(int p, int q)
{
    int st = p, dr = q, x = v[p];
    while(st < dr)
    {
        while(st < dr && v[dr] >= x)
            dr--;
        v[st] = v[dr];
        while(st < dr && v[st] <= x)
            st++;
        v[dr] = v[st];
    }
  v[st] = x;
  return st;
}

void qsort(int p, int q)
{
    int m = divide(p, q);
    if(m-1> p) qsort(p, m-1);
    if(m-1 < q) qsort(m+1, q);
}

int main()
{
    f >> n;
    for(int i = 1; i <= n; i++)
        f >> v[i];
    qsort(1, n);
    genpermutari(1);
    f.close();
    g.close();
    return 0;
}
