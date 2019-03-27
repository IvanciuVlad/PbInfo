#include<iostream>
#include<cmath>
using namespace std;
int n, pn;


void gen(int strat, int a)
{
    if(strat == 1)
        cout << 1 << " ";
    if(pow(2, strat) <= pn)
    {
        int k = pow(2, strat);
        for(int i = 1; i <= k/2; i++)
        {
            cout << a << " ";
            a++;
        }
        gen(strat + 1, a+k/2);
        for(int i = k/2+1; i <= k; i++)
            {
            cout << a << " ";
            a++;
        }
    }
    if(strat == 1)
        cout << 2 << " ";
}

int main()
{
    cin >> n;
    pn = pow(2, n-1);
    gen(1, 3);
    return 0;
}
