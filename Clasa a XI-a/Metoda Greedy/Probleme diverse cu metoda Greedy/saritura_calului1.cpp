#include<fstream>
using namespace std;

ifstream f("saritura_calului1.in");
ofstream g("saritura_calului1.out");
int n, m, is, js, viz[105][105], nr_mutari;
int dl[8]={-2,-2,-1,-1,+1,+1,+2,+2};
int dc[8]={-1,+1,-2,+2,-2,+2,-1,+1};

int coef(int l, int c)
{
    int k, cnt = 0;
    for(k = 0; k < 8; k++)
    {
        if(l + dl[k] >= 1 &&
                l + dl[k] <= n &&
                c + dc[k] >= 1 &&
                c + dc[k] <= m &&
                !viz[l + dl[k]][c + dc[k]])
            cnt++;
    }
    return cnt;
}

void greedy(int l, int c)
{
    viz[l][c] = nr_mutari;

    if(nr_mutari == n * m)
        return;
    nr_mutari++;
    int k, gasit = 0, a, cmin = 9, nl, nc;
    for(k = 0; k < 8; k++)
        if(l + dl[k] >= 1 &&
                l + dl[k] <= n &&
                c + dc[k] >= 1 &&
                c + dc[k] <= m &&
                !viz[l + dl[k]][c + dc[k]])
        {
            a = coef(l + dl[k], c + dc[k]);
            if(a < cmin)
            {
                cmin = a;
                nl = l + dl[k];
                nc = c + dc[k];
                gasit = 1;
            }
        }
    if(gasit)
    {
        greedy(nl, nc);
    }

}


int main()
{
    f >> n >> m >> is >> js;
    nr_mutari = 1;
    greedy(is, js);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            g << viz[i][j] << " ";
        g << endl;
    }

    f.close();
    g.close();
    return 0;
}