#include<fstream>
using namespace std;

ifstream f("cerc.in");
ofstream g("cerc.out");

int s[12], v[12], ss, sm, m[12], n, uz[12];

void scriem()
{
    for(int i = 1; i <= n; i++)
        g << v[m[i]] << " ";
}

void comparare()
{
    ss = 0;
    for(int i = 2; i <= n; i++)
        ss = ss + v[s[i]]*v[s[i-1]];
    ss = ss + v[s[1]]*v[s[n]];
    if(ss > sm)
    {
        for(int i = 1; i <= n; i++)
            m[i] = s[i];
        sm = ss;
    }
}

void bkt(int k)
{
    if(k-1 == n)
        comparare();
    else
        for(int i = 1; i <= n; i++)
            if(!uz[i])
            {
                s[k] = i;
                uz[i] = 1;
                bkt(k+1);
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
    int s = divide(p, q);
    if(s-1 > p) qsort(p, s-1);
    if(s+1 < q) qsort(s+1, q);
}


int main()
{
    f >> n;
    for(int i = 1; i <= n; i++)
        f >> v[i];
    f.close();
    qsort(1, n);
    s[1] = 1;
    bkt(2);
    scriem();
    g.close();
    return 0;
}
