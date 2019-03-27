#include<iostream>
using namespace std;

int main()
{
    long a, b, aux;
    cin >> a >> b;
    if(a == 0 && b == 0)
        cout << -1;
    else if(a == 0)
        cout << b;
    else if(b == 0)
        cout << a;
    else
    {
        while(a && b)
        {
            if(a % b == 0)
                break;
            else
                {
                    aux = a;
                    a = b;
                    b = aux % b;
                }
        }
        cout << b;
    }
    return 0;
}
