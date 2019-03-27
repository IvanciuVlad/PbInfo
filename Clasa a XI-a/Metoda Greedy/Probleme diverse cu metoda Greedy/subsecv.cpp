#include<fstream>
#include<iostream>
using namespace std;

ifstream f("subsecv.in");
ofstream g("subsecv.out");
int n, li, ls;
unsigned long v[10001], maxim, s;

int main()
{
    int i, j;
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> v[i];
        v[i] %= n;

    }
    for(i = 1; i <= n; i++)
    {
        s = 0;
        for(j = i; j <= n; j++)
          {
              s = (s + v[j])%n;
              if(s%n == 0)
              {
                  g << i << " " << j;
                  i = n;
                  break;
              }
          }
    }
    f.close();
    g.close();
    return 0;
}
