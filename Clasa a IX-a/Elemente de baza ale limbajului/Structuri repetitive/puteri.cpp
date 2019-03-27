#include<iostream>

int main()
{
    unsigned long long a, b, n, i, v[10000];
    std::cin >> n;
    for(i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        long j, d = 0;
        if(a > b)
        {
            a = a+b;
            b = a-b;
            a = a-b;
        }
        /*if(b%2 == 1)
            b--;*/
        while(a&(a-1)) a = a&(a-1);
        while(b&(b-1)) b = b&(b-1);
        /*for(j = b; j >= a; j=j-2)
            if((j & (j-1)) == 0)
        {
            d = j;
            break;
        }*/
        if(b > a)
            d = b;
        v[i] = d;
    }
    for(i = 0; i < n; i++)
        std::cout << v[i] << std::endl;
    return 0;
}