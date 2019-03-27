#include<iostream>
using namespace std;

int n, a[101], m, ma, no;

int main()
{
    int x, y;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[y]++;
    }
    for(int i = 1; i <= n; i++)
        if(a[i] > ma)
        {
            ma = a[i];
        }
    for(int i = 1; i <= n; i++)
        if(a[i] == ma)
            cout << i << " ";
}
