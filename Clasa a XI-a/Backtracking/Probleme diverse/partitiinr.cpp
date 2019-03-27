#include<fstream>
using namespace std;

ifstream f("partitiinr.in");
ofstream g("partitiinr.out");
int n, sum, s[120];

void scrie(int lg)
{
    for(int i = 1; i <= lg; i++)
        g << s[i] << " ";
    g << endl;
}

int valid(int k)
{
    for(int i = 1; i < k; ++i)
        if(s[i] > s[i+1] || (s[i+1] - s[i] < 2))
            return 0;
    return 1;
}


void bkt(int k)
{
    if(sum == n)
        scrie(k - 1);
    else
        for(int i = s[k-1]+1; i <= n - sum; i++)
        {
            s[k] = i;

            if(valid(k))
            {
                sum += i;
                bkt(k + 1);
                sum -= i;
            }

        }

}


int main()
{
    f >> n;
    s[0] = 0;
    bkt(1);
    f.close();
    g.close();
    return 0;
}
