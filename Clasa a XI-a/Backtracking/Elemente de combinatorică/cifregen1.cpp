#include<iostream>
using namespace std;

int n, m, s[10];


void scrie()
{
  if(s[1] == 0)
    return;
  for(int i = 1; i <= n; i++)
    	cout << s[i];
    cout << endl;
}

void gen(int k)
{
    if(k == n+1)
            scrie();
    else
        for(int i = 0; i < m; i++)
    {
        s[k] = i;
        gen(k+1);
    }
}

int main()
{
    cin >> n >> m;
    gen(1);
    return 0;
}
