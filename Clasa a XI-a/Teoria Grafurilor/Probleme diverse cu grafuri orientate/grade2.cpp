#include<iostream>
using namespace std;

int n, m, dp[101], dm[101], c;

int main()
{
    int x, y;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)\
    {
        cin >> x >> y;
        dp[x]++;
        dm[y]++;
    }
    for(int i = 1; i <= n; i++)
        if(dm[i] == dp[i])
            c++;
    cout << c << endl;
    for(int i = 1; i <= n; i++)
        if(dm[i] == dp[i])
            cout << i << " ";
    return 0;
}
