#include<iostream>
using namespace std;

int n, m, x, y, a[10][10], ready;
int dl[8] = {-1,1,2,2,1,-1,-2,-2};
int dc[8] = {2,2,1,-1,-2,-2,-1,1};
void scrie()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void bkt(int k, int lin, int col)
{
    if(ready)
        return;
    if(k == n * m)
    {
        ready = 1;
        return;
    }
    else
    {
        int linia, coloana, i;
        for(i = 0; i < 8; i++)
        {
            coloana = col + dc[i];
            linia = lin + dl[i];
            if(linia  < 1 || linia > n || coloana < 1 || coloana > m || a[linia][coloana])
                continue;
            a[linia][coloana] = k + 1;
            bkt(k + 1, linia, coloana);
            if(!ready)
                a[linia][coloana] = 0;


        }
    }
}

int main()
{
    cin >> n >> m >> x >> y;
    a[x][y] = 1;
    bkt(1, x, y);
    scrie();
    return 0;
}
