#include<fstream>
using namespace std;
ifstream f("sclm.in");
ofstream g("sclm.out");

int n, v[1002], l[1002];

int main()
{
    int i, j, lmax, pmax;
    f >> n;
    for(i = 1; i <= n; i++)
        f >> v[i];
    l[n] = 1;
    for(i = n-1; i >= 1; i--)
    {
        lmax = 0;
        for(j = i+1; j <= n; j++)
            if(v[i] < v[j] && lmax < l[j])
                lmax = l[j];
        l[i] = lmax + 1;
    }
    lmax = l[1];
    pmax = 1;
    for(i = 2; i <= n; i++)
    {
        if(l[i] > lmax)
        {
            lmax = l[i];
            pmax = i;
        }
    }
    g << lmax << endl;
    while(lmax)
    {
        g << pmax << " ";
        lmax--;
        for(i = pmax+1; i <= n; i++)
            if(l[i] == lmax && v[pmax] < v[i])
            {
                pmax = i;
                break;
            }
    }
    f.close();
    g.close();
    return 0;
}
