#include<algorithm>
#include<fstream>
using namespace std;
ifstream in("veriflant.in");
ofstream out("veriflant.out");

int a[110][110],n, k, v[210], m, nn, i, j, x, y;

int main()
{
    in >> n >> m;
    for(i = 1; i <= m; i++)
        {
            in >> x >> y;
            a[x][y] = a[y][x] = 1;
        }
    in >> k;
    for(i = 1; i <= k; i++)
    {
        int ok1 = 1;
        in >> nn >> x;
        v[1] = x;
        for(j = 2; j <= nn; j++)
        {
            in >> y;
            v[j] = y;
            if(a[x][y] == 0)
                ok1 = 0;
            x = y;
        }
        if(ok1)
        {
            sort(v+1, v+nn+1);
            int ok2 = 1;
            for(j = 2; j <= nn; j++)
            {
                if(v[j-1] == v[j])
                {
                    out << "NEELEMENTAR" << endl;
                    ok2 = 0;
                    break;
                }
            }
            if(ok2)
                out << "ELEMENTAR" << endl;
        }
        else
            out << "NU" << endl;
    }
}
