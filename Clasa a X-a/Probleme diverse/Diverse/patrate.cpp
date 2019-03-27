#include<iostream>
using namespace std;

int main()
{
    unsigned long long n, t1, t2, d = 666013;
    cin >> n;
    t1 = (n*(n+1))/2;
    t2 = (n + 1)*(n + 2)/2;
    if(t1%3 == 0)
        t1 /= 3;
    else
        t2 /= 3;

    cout << ((t1%d) * (t2%d))%d;
    return 0;
}
