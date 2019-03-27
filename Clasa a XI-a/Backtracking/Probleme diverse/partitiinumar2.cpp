#include<fstream>
using namespace std;

ifstream f("partitiinumar2.in");
ofstream g("partitiinumar2.out");
int n, sum, s[250], m, uz[40];

void scrie(int lg)
{
    for(int i = 1; i <= lg; i++)
        g << s[i] << " ";
    g << endl;
}


void bkt(int k)
{
    if(sum == n && k > m)
        scrie(k - 1);
    else
        for(int i = s[k-1]; i <= n - sum; i++)
        {
                if(!uz[i])
                {
                s[k] = i;
                sum += i;
                uz[i] = 1;
                bkt(k + 1);
                sum -= i;
                uz[i] = 0;
                }

        }
}

int main()
{
    f >> n >> m;
    s[0] = 1;
    bkt(1);
    f.close();
    g.close();
    return 0;
}
