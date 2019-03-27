#include<fstream>
#include<math.h>
using namespace std;
#define EPS 1e-5
ifstream f("nsir.in");
ofstream g("nsir.out");
int n, sum, s[200], ok;

void scrie(int lg)
{
    double su = 0;
    for(int i = 1; i <= lg; i++)
        su += 1.0/s[i];
    if(fabs(su- 1.0) > EPS)
        return;
    ok = 1;
    for(int i = 1; i <= lg; i++)
        g << s[i] << " ";
    g << endl;
}

int verificare(int lg)
{
    double su = 0;
    for(int i = 1; i <= lg; i++)
        su += 1.0/s[i];
    if(fabs(su - 1.0) > 1.0 + 10 * EPS)
        return 0;
    return 1;
}

void bkt(int k)
{
    if(sum == n)
        scrie(k - 1);
    else
        for(int i = s[k-1]; i <= n - sum; i++)
    {
        s[k] = i;
        sum += i;
        if(verificare(k))
            bkt(k + 1);
        sum -= i;
    }
}

int main()
{
    f >> n;
    s[0] = 1;
    bkt(1);
    if(ok == 0)
        g << "0";
    f.close();
    g.close();
    return 0;
}
