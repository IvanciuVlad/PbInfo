int sum_div(int x)
{
    int i, s = x;
    for(i = 1; i <= x/2; i++)
        if(x%i == 0)
            s += i;
    return s;
}