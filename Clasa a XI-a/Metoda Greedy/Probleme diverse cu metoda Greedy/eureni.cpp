#include<fstream>
using namespace std;
ifstream f("eureni.in");
ofstream g("eureni.out");

int main()
{
    long s, v[11], p;
    int i, n, e, t = 0;
    f >> s >> n >> e;
    v[0] = 1;
    p = e;
    for(i = 1; i <= n; i++)
    {
        v[i] = p;
        p *= e;
    }

    for(i = n; i >= 0; i--)
        if(s >= v[i])
    {
        int nr = s/v[i];
        s -= v[i]*nr;
        g << v[i] << " " << nr << endl;
        t += nr;
    }
    g << t;
    f.close();
    g.close();
    return 0;
}
