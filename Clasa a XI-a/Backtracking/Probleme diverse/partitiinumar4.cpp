#include<fstream>
using namespace std;

ifstream f("partitiinumar4.in");
ofstream g("partitiinumar4.out");
int n, sum, s[41], m, v[41], h;

void scrie(int lg)
{
    for(int i = 1; i <= lg; i++)
        g << v[s[i]] << " ";
    g << endl;
}

void bkt(int k)
{
    if(sum == n)
        scrie(k - 1);
    else if(sum < n)
        for(int i = s[k-1]; i <= min(n - h, m); i++)
        {
            s[k] = i;
            sum += v[i];
            h += i;
            bkt(k + 1);
            sum -= v[i];
            h -= i;
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
    int r = divide(p, q);
    if(r-1 > p) qsort(p, r-1);
    if(r+1 < q) qsort(r+1, q);
}


int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; i++)
        f >> v[i];
    qsort(1, m);
    s[0] = 1;
    bkt(1);
    f.close();
    g.close();
    return 0;
}
