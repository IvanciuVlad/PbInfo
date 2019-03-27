#include<fstream>
using namespace std;

int n, s[12];
ifstream f("submultimi1.in");
ofstream g("submultimi1.out");

void scrie(int k)
{
    for(int i = 1; i <= k; i++)
        g << s[i] << " ";
    g << endl;
}

int valid(int k)
{
  if(k == 1)
    return 1;

  if(s[k] - s[k - 1] <= 1)
    return 0;
  return 1;
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
            if(valid(k))
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
