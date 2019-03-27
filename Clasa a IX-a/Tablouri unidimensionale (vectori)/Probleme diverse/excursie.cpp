#include<iostream>
using namespace std;

int ok, a[2003], b[2003], n, x, y;

int main()
{

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a[i] = x;
        a[i + n] = x;
        b[i] = y;
        b[i + n] = y;
    }
    a[n + n + 1] = a[n];
    for(int i = 1; i <= n; i++)
    {
        int e = 0, j = 0;
        while(j < n && e >= 0)
        {
            e += b[i+j];
            e -= a[i+j];
            j++;
        }
        if(j == n && e >= 0)
            ok = 1, cout << i;
        if(ok == 1)
            break;

    }
    if(!ok)
        cout << -1;
}
