#include<iostream>

unsigned long long n, x, a, b;

int main()
{
    int i;
    std::cin >> n;
    for(i = 0; i < n; i++)
    {
        std::cin >> x;
        if(x%2 == 1)
        {
            b = a;
            a = x;
        }
    }
    if(a && b)
        std::cout << b << " " << a;
    else
        std::cout << "Numere insuficiente";
}
