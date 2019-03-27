#include<fstream>
using namespace std;

ifstream f("masini.in");
ofstream g("masini.out");
int n, k, t, v[1010];


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
    int r = divide(p, q);
    if(r-1 > p) qsort(p, r-1);
    if(r+1 < q) qsort(r+1, q);
}

int main()
{
    f >> n >> t;
    for(int i = 1; i <= n; i++)
        f >> v[i];
    qsort(1, n);
    for(int i = 1; i <= n; i++)
        if(v[i] <= t)
        {
            k++;
            t -= v[i];
        }
        else
            break;
    g << k;
    f.close();
    g.close();
    return 0;
}
