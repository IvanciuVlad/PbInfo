int cifmax(long n)
{
    int a, b;
    if(n == 0)
        return 0;
    else
        {
        a = n % 10;
        b = cifmax(n / 10);
        if(a > b)
            return a;
        else
            return b;
        }
}
