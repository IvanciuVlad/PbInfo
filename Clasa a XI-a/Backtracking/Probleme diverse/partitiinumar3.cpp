#include<fstream>
using namespace std;

ifstream f("partitiinumar3.in");
ofstream g("partitiinumar3.out");
int n, sum, s[200], a, b;

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
        for(int i = s[k-1]; i <= n - sum && i <= b; i++)
    {
        s[k] = i;
        sum += i;
        bkt(k + 1);
        sum -= i;
    }
}

int main()
{
    f >> n >> a >> b;
    s[0] = a;
    bkt(1);
    f.close();
    g.close();
    return 0;
}