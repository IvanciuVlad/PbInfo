#include<fstream>
using namespace std;

int n, m, a[20][20], s[200][2], is, js, ib, jb, cnt;
int dl[5] = {0, -1, 0, 1, 0};
int dc[5] = {0, 0, 1, 0, -1};
ifstream f("soarece.in");
ofstream g("soarece.out");

int valid(int k, int lin, int col)
{
    if(a[lin][col])
        return 0;
    for(int i = 1; i < k; i++)
        if(s[i][0] == lin && s[i][1] == col)
            return 0;
    return 1;
}

void bkt(int k, int lin, int col)
{
    if(lin == 0 || col == 0 || lin > n || col > m)
        return;
    if(lin == ib && col == jb)
        cnt++;
    else
    {
        int i;
        s[k][0] = lin;
        s[k][1] = col;
        for(i = 1; i <= 4; i++)
        {
            int coloana = col + dc[i];
            int linia = lin + dl[i];
            if(valid(k, linia, coloana))
                bkt(k + 1, linia, coloana);
        }
    }
}

int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f >> a[i][j];
    f >> is >> js >> ib >> jb;
    bkt(n, is, js);
    g << cnt;
    f.close();
    g.close();
    return 0;
}
