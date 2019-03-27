#include <fstream>

using namespace std;
ifstream in("summax.in");
ofstream out("summax.out");
int n,s[12],smax,a[20][20],v[11];

void calc()
{
    int sc = 0;
    for(int i = 1; i <= n; ++i)
        sc+=v[i];
    if(sc > smax){
        smax = sc;
    }

}
int valid(int k)
{
    for(int i = 1; i<k; ++i)
        if(s[i] == s[k])
            return 0;
    return 1;
}
void bkt()
{
    int k = 1, up, cnt = 0;
    s[k] = 0;
    while(k)
    {
        up = 0;
        while(!up && s[k] < n)
        {
            s[k]++;


            if(valid(k)){
                up = 1;

                v[k] = a[k][s[k]];
            }
        }
        if(up)
        {
            if( k == n){

                    calc();

            }
            else
                {
                    k++;
                    s[k] = 0;
                }
        }
        else
            k--;
    }
}
int main()
{
    in>> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            in >> a[i][j];
    bkt();
    out<< smax;
    return 0;
}