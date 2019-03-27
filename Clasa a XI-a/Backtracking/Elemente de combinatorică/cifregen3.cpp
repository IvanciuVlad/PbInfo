#include<iostream>
using namespace std;

int n, s[10], m;



void scrie()
{
    for(int i = 1; i < n; i++)
        cout << s[i];
    cout << s[1];
    cout << endl;
}

int valid(int k)
{
    if(k == 1)
        if(s[k] == 0)
            return 0;
        else
            return 1;
}

void gen(int k)
{
    if(k == n)
        scrie();
    else
        for(int i = 0; i < m; i++)
        {
            s[k] = i;
            if(valid(k))
                gen(k+1);
        }
}

int main()
{
    cin >> n >> m;
    gen(1);
    return 0;
}
