#include<fstream>
using namespace std;
ifstream f("paranteze.in");
ofstream g("paranteze.out");

int n, nd, ni, s[22];
char sir[4] = " ()";

void scrie()
{
    for(int i = 1; i <= n;  i++)
        g << sir[s[i]];
    g << endl;
}

int valid(int k)
{
    int i, nd = 0, ni = 0;
    for(i = 1; i <= k; i++)
        if(s[i] == 1)
            nd++;
        else
            ni++;
    if(nd > n/2 || nd < ni)
        return 0;
    return 1;
}

void bkt()
{
    int k = 1, up;
    s[k] = 0;
    while(k)
    {
        up = 0;
        while(!up && s[k] < 2)
        {
            s[k]++;
            if(valid(k))
                up = 1;
        }
        if(up)
        {
            if(k == n)
                scrie();
            else
                s[++k] = 0;
        }
        else
            k--;
    }
}

int main()
{
    f >> n;
    bkt();
    g.close();
    return 0;
}
