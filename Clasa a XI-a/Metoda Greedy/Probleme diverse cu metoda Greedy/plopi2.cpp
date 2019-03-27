#include<fstream>
using namespace std;
ifstream f("plopi2.in");
ofstream g("plopi2.out");

int main()
{
    int n, v[101], i, nr = 0, buc = 0;
    f >> n;
    for(i = 1; i <= n; i++)
        f >> v[i];

    for(i = 1; i < n; i++)
        if(v[i] < v[i+1])
    {
        nr++;
        buc += (v[i+1]-v[i]);
        v[i+1] = v[i];
    }
    g << nr << " " << buc;
    f.close();
    g.close();
    return 0;
}
