#include<fstream>
using namespace std;

int n, s[12];
ifstream f("submultimi.in");
ofstream g("submultimi.out");

void scrie(int k)
{
    for(int i = 1; i <= k; i++)
        g << s[i] << " ";
    g << endl;
}

void bkt()
{
    int k = 1, up;
    s[k] = 0;
    while(k)
    {
        up = 0;
        while(!up && s[k] < n)
        {
            s[k]++;
            up = 1;
        }
        if(up)
        {
            scrie(k);
            if(k < n)
            {
                k++;
                s[k] = s[k-1];
            }
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
    return 0;
}
