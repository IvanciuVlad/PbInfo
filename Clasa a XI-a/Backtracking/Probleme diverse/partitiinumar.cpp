#include<fstream>
using namespace std;

ifstream f("partitiinumar.in");
ofstream g("partitiinumar.out");
int n, sum, s[200];

void scrie(int lg)
{
    for(int i = 1; i <= lg; i++)
        g << s[i] << " ";
    g << endl;
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
        bkt(k + 1);
        sum -= i;
    }
}

int main()
{
    f >> n;
    s[0] = 1;
    bkt(1);
    f.close();
    g.close();
    return 0;
}
