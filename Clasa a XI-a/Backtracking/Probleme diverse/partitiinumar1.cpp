#include<fstream>
using namespace std;

ifstream f("partitiinumar1.in");
ofstream g("partitiinumar1.out");
int n, sum, s[300], uz[41];

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
    f >> n;
    s[0] = 1;
    bkt(1);
    f.close();
    g.close();
    return 0;
}
