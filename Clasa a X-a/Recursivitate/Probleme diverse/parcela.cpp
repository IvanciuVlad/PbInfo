#include <iostream>
#include <fstream>
using namespace std;
ifstream in("parcela.in");
ofstream out("parcela.out");

int a[101][128],m,n,c=1, smax,s,cmax;

int di[] = {0,-1,0,1};
int dj[] = {-1,0,1,0};

void fill(int i, int j){
    a[i][j] = c;
    s++;
    for(int k = 0; k<4;++k) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if(ni<1 || ni>m || nj<1 || nj>n || a[ni][nj]!=1)
            continue;
        fill(ni,nj);
    }
}
int main()
{
    int i, j;
    in>>m>>n;
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
            in>>a[i][j];

    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
            if(a[i][j]==1) {
                c++;
                s = 0;
                fill(i, j);
                if(s>smax) {
                    smax = s;
                    cmax = c;
                }
            }
  
    out<<c-1<<" "<<smax<<" "<<cmax-1;
    return 0;
}