#include<fstream>
std::ifstream in("bifrunze.in");
std::ofstream out("bifrunze.out");
int n, st[1001], dr[1001];

int main()
{
    int x;
    in >> n;
    for(int i = 1; i <= n; i++)
        in >> x >> st[i] >> dr[i];

    for(int i = 1; i <= n; i++)
        if(!st[i] && !dr[i])
            out << i << " ";
}
