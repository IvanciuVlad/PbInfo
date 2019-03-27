#include<fstream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
ifstream f("spectacole.in");
ofstream g("spectacole.out");

struct show
{
    int start, en;
};
typedef show *ps;
show v[100], s[100];
int n, m;

void citire()
{
    f >> n;
    for(int i = 0; i < n; i++)
        f >> v[i].start >> v[i].en;
}

/*void sortare()
{
    for(int i = 0; i < n-1; i++)
        for(int j = i + 1; j < n; j++)
            if(v[i].en > v[j].en)
                swap(v[i], v[j]);
}*/

void greedy()
{
    s[0] = v[0];
    m = 1;
    int sfarsit = v[0].en;
    for(int i = 1; i < n; i++)
        if(v[i].start >= sfarsit)
    {
        s[m++] = v[i];
        sfarsit = v[i].en;
    }
}

int fcmp(const void *a, const void *b)
{
    if((ps(a))->en > (ps(b))->en)
       return 1;
    else if((ps(a))->en < (ps(b))->en)
        return -1;
    else
        return 0;
}

int main()
{
    citire();
    qsort(v, n, sizeof(v[0]), fcmp);
    greedy();
    g << m;
    f.close();
    g.close();
    return 0;
}
