#include<fstream>
using namespace std;
ifstream f("sumtri1.in");
ofstream g("sumtri1.out");
int n, a[101][101], s[101][101];

void citire()
{
    f >> n;
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= i; j++)
            f >> a[i][j];
}

int main()
{
    citire();
    int i, j;
    for(i = 1; i <= n; i++)
        s[n][i] = a[n][i];
    for(i = n-1; i >= 1; i--)
        for(j = 1; j <= i; j++)
            s[i][j] = a[i][j] + min(s[i+1][j], s[i+1][j+1]);
    g << s[1][1] << endl;
    j = 1;
    g << a[1][1] << " ";
    for(i = 2; i <= n; i++)
    {
        /*int mi = 10000002, poz;
        for(j = 1; j <= i; j++)
        {
            if(s[i][j] <= mi)
            {
                mi = s[i][j];
                poz = j;
            }
        }
        g << a[i][poz]<< " ";*/
        if(s[i][j] >  s[i][j+1])
        {
            g << a[i][j+1] << " ";
            j++;
        }
        else
        {

            g << a[i][j] << " ";

        }

    }

    f.close();
    g.close();
    return 0;
}
