#include<iostream>
using namespace std;

int n, a, b, s[10];


void scrie()
{
  for(int i = 1; i <= n; i++)
    	cout << s[i];
  cout << endl;
}

void gen(int k)
{
    if(k == n+1)
        scrie();
    else
        for(int i = a; i <= b; i++)
    {
        s[k] = i;
        gen(k+1);
    }
}

int main()
{
    cin >> a >> b >> n;
    gen(1);
    return 0;
}
