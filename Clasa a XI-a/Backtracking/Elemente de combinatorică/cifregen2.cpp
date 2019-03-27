#include<iostream>
using namespace std;

int n, s[10], v[7];



void scrie()
{
    for(int i = 1; i <= n; i++)
        cout << v[s[i]];
    cout << endl;
}

void gen(int k)
{
    if(k == n+1)
        scrie();
    else
        for(int i = 1; i <= 4; i++)
        {
            s[k] = i;
            gen(k+1);
        }
}

int main()
{
    cin >> n;
    v[1] = 2;
    v[2] = 3;
    v[3] = 5;
    v[4] = 7;
    gen(1);
    return 0;
}
