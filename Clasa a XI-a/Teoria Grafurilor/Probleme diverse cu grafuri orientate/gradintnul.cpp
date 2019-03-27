#include<iostream>
using namespace std;

int n, m, dm[101], ok = 1;

int main()
{
    int x, y;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        dm[y]++;
    }
    for(int i = 1; i <= n; i++)
        if(dm[i] == 0)
        {
            cout << i << " ";
            ok = 0;
        }
    if(ok)
        cout << "NU EXISTA";
    return 0;
}
