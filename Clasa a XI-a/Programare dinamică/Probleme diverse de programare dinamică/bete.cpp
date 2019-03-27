#include<fstream>
#include<iostream>
using namespace std;

ifstream f("bete.in");
ofstream g("bete.out");
int n, v[1001], l[100100], s;

void afisare(int s, int k)
{
    if(s > 0)
    {
        afisare(s - v[l[s]], k+1);
        g << l[s] << " ";
    }
    else
    {
        g << k << endl;
    }
}

int main()
{
    int i, j;
    f >> n >> s;
    for(i = 1; i <= n; i++)
        f >> v[i];

    for(i = 1; i <= s + 100; i++)
        l[i] = n+1;

    for(j = 1; j <= n; j++)
        for(i = 0; i + v[j] <= s; i++)
            if(l[i+ v[j]] == n+1 && l[i] < j)
            {
                l[i + v[j]] = j;
                if(l[i + v[j]] == s)
                    break;
            }

    if(l[s] == n+1)
        g << "NU";
    else
    {
        g << "DA" << endl;;
        afisare(s, 0);
    }
    f.close();
    g.close();
    return 0;
}
