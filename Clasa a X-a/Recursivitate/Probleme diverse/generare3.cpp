#include<iostream>
using namespace std;

int f[20], n;

void afisare()
{
    for(int i = 1; i <= n; i++)
        cout << f[i];
    cout << endl;
}

void GenAranjamente(int k)
{
    if(k-1 == n)
        afisare();
    else
        for(int i = 0; i <= 1; i++)
    {
        f[k] = i;
        GenAranjamente(k+1);
    }
}



int main()
{
    cin >> n;
    GenAranjamente(1);
    return 0;
}
