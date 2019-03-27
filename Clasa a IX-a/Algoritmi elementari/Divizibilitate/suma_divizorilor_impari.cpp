#include<iostream>

long long n, s, i;

int main()
{
    std::cin >> n;

    for(i = 1; i*i <= n; i++)
        if(n%i == 0)
            {
                if(i%2 == 1)
                    s += i;
                //std::cout << s << " ";
                if((n/i)%2 == 1)
                    s += n/i;
                //std::cout << s << " ";
            }
    std::cout << s;
    return 0;
}
