#include<fstream>
using namespace std;

int s[10], n;

ifstream f("permutari1.in");
ofstream g("permutari1.out");
void scrie()
{
    for(int i = 1; i <= n; i++)
            g << n - s[i] + 1 << " ";
    g << '\n';

}

int valid(int k)
{
    for(int i = 1; i < k; i++)
        if(s[k] == s[i])
            return 0;
    return 1;
}

void bkt()
{
    int k = 1, up;
    while(k)
    {
        up = 0;
        while(!up && s[k] < n)
        {
            s[k]++;
            if(valid(k))
                up = 1;
        }
        if(up)
            if(k == n)
                scrie();
            else
            {
                k++;
                s[k] = 0;
            }
        else
            k--;
    }
}

int main()
{
    f >> n;
    bkt();
    f.close();
    g.close();
}
