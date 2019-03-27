#include<fstream>
using namespace std;

int n, m, s[10];
ifstream f("produscartezian1.in");
ofstream g("produscartezian1.out");

void scrie()
{
  for(int i = 1; i <= m; i++)
    	g << s[i] << " ";
  g << endl;
}

void gen(int k)
{
    if(k == m+1)
        scrie();
    else
        for(int i = 1; i <= n; i++)
    {
        s[k] = i;
        gen(k+1);
    }
}

int main()
{
    f >> n >> m;
    f.close();
    gen(1);
    g.close();
    return 0;
}
