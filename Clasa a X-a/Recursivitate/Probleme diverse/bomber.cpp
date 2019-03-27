#include<fstream>
using namespace std;
ifstream f("bomber.in");
ofstream g("bomber.out");
int n, I, x[101], y[101], p[101], ex[101], C;

void explozie(int k)
{
    int i, d = 0;
    ex[k] = 1;
    for(i = 1; i <= n; i++)
        if(!ex[i])
    {
        d = ((x[i] - x[k]) * (x[i] - x[k])) + ((y[i] - y[k]) * (y[i] - y[k]));
        if(d <= (p[k] * p[k]))
            explozie(i);
    }
}

int main()
{
    int i;
    f >> n >> I;
    for(i = 1; i <= n; i++)
        f >> x[i] >> y[i] >> p[i];

    f.close();
    explozie(I);
    for(i = 1; i <= n; i++)
        if(!ex[i])
            C++;
    g << C;
    g.close();
    return 0;
}
