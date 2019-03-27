#include<fstream>
#include<algorithm>
#include<stdlib.h>
#include<sstream>
#include<cstring>
using namespace std;
ifstream f("concert.in");
ofstream g("concert.out");


int sec[100], s[100], id[1000];
int n, m, t, mi, se;

void citire()
{
    f >> n >> t;
    for(int i = 0; i < n; i++)
    {
        string sir;
        f >> sir;
        for(int j = 0; j < sir.size(); j++)
            if(sir[j] == ':')
                sir[j] = ' ';
        istringstream ss(sir);
        ss >> mi >> se;
        sec[i] = mi*60 + se;
        id[i] = i+1;
    }
}




void sortare()
{
    for(int i = 0; i < n-1; i++)
        for(int j = i+1;  j < n; j++)
            if(sec[j] < sec[i])
            {
                swap(sec[i], sec[j]);
                swap(id[i], id[j]);
            }
}


int main()
{
    citire();
    sortare();
    m = 0;
    for(int i = 0; i < n; i++)
    {
        if(sec[i] <= t)
        {
            m++;
            t -= sec[i];
        }
        else
            break;
    }
    sort(id, id + m);
    g << m << endl;
    for(int i = 0; i < m; i++)
        g << id[i] << " ";
    f.close();
    g.close();
    return 0;
}
