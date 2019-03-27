#include<fstream>
using namespace std;

ifstream f("suma35.in");
ofstream g("suma35.out");
int n, sum, s[2000];

int valid(int k)
{
    if(k == 1)
        return 1;
    if(!(s[k - 1] <= s[k]))
        return 0;
    return 1;
}

void scrie(int lg)
{
    for(int i = 1; i <= lg; i++)
        g << s[i]*2+1 << " ";
    g << endl;

}

void bkt(int k)
{
    if(sum == n)
        scrie(k - 1);
    else if(sum < n)
        for(int i = 1; i <= 2; i++)
        {

            s[k] = i;
            if(valid(k))
            {
                sum += i*2 + 1;
                bkt(k + 1);
                sum -= i*2 + 1;
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
