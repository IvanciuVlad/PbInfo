#include<fstream>
std::ifstream in("frunze.in");
std::ofstream out("frunze.out");

int v[102], r, n, rad[102], f;

int main()
{
    in >> n;
    f = n;
    for(int i = 1; i <= n; i++)
    {
        in >> v[i];
        if(v[i] == 0)
            r = i;
        if(rad[v[i]] == 0)
            f--;
        rad[v[i]] = 1;
    }
   out << r << "\n";
   out << f+1 << "\n";
   for(int i = 1; i <= n; i++)
            if(!rad[i])
                out << i << " ";
}
