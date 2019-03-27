#include<fstream>
std::ifstream in("graf_complet.in");
std::ofstream out("graf_complet.out");

int g;

void verif(int n, int a[51][51])
{
    int ok = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
            if(!a[i][j])
            {
                ok = 0;
                break;
            }
    }
    if(ok)
        out << "DA \n";
    else
        out << "NU \n";
}

int main()
{
    in >> g;
    for(int i = 1; i <= g; i++)
    {
        int n, a[51][51];
        in >> n;
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                in >> a[j][k];
        verif(n, a);
    }
    in.close();
    out.close();
    return 0;
}
