#include<fstream>
using namespace std;
ifstream f("plusminus.in");
ofstream g("plusminus.out");
int n, s[25], ok;


void scrie()
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
        if(s[i] == 1)
            sum += i * i;
        else
            sum -= i * i;
    if(sum == n)
    {
        ok = 1;
        for(int i = 1; i <= n; i++)
            if(s[i])
                g << "+ ";
            else
                g << "- ";
        g << endl;
    }
}


void bkt(int k)
{
    if(k == n+1)
        scrie();
    else
    {
        for(int i = 0; i <= 1; i++)
            s[k] = i, bkt(k+1);
    }
}


int main()
{
    f >> n;
    bkt(1);
    if(ok == 0)
        g << "IMPOSIBIL";
    f.close();
    g.close();
    return 0;
}
