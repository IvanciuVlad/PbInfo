long elimcif(long n, int c)
{
    long v[12], i, j, nx = 0, nrc = 0;
    while(n)
    {
        v[++nrc] = n % 10;
        n /= 10;
    }
    for(i = nrc; i >= 1; i--)
        if(v[i] != c)
            nx = nx * 10 + v[i];
    return nx;
}