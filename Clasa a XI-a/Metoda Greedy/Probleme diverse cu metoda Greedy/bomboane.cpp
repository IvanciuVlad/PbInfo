#include <iostream>
#include <fstream>
using namespace std;
ifstream in("bomboane.in");
ofstream out("bomboane.out");
/*struct action
{
    int f,d,c;
} mutari[1300];
*/
int n,v[1003],w[1003][3];
int main()
{
    int s = 0,med;
    in >> n;
    for(int i = 1; i <= n; ++i)
    {
        in >> v[i];
        s += v[i];
    }
    med = s/n;
    if(!(med * n==s))
    {
        out << -1;
        return 0;
    }

    int m,M,pm,pM,nr = 0;
    do
    {
        m = s;
        M = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(v[i] < m)
            {
                m = v[i];
                pm = i;
            }
            if(v[i] > M)
            {
                M = v[i];
                pM = i;
            }
        }
        //int bom = med - m;
        nr++;
        w[nr][0] = pM;
        w[nr][1] = pm;
        w[nr][2] = M- med;
        //v[pM] = M - bom;
        //v[pm] += bom;
        v[pM] = med;
        v[pm] += w[nr][2];
        //nr++;
    }
    while(m != M);

    out << nr-1 << endl;
    for(int i = 1; i < nr; ++i)
        out <<  w[i][0]<< " " <<  w[i][1]<<" "<< w[i][2]<<endl;
    //cout << endl;
    //for(int i = 1; i <= n; ++i)
        //cout << v[i] << " ";
    return 0;
}