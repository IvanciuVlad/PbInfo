#include<iostream>
using namespace std;

int a[101][100], n, m, ord, x;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                if(i != j)
            {
                cin >> x;
                a[i][j] = x;
            }
        }
    for(int i = 1; i <= n; i++)
        {
            x = 0;
            for(int j = 1; j <= n; j++)
                x += a[j][i];
            if(x > m)
                m = x, ord = i;
        }
    cout << ord;
    return 0;
}
