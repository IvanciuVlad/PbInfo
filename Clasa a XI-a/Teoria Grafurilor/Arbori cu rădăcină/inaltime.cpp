#include<fstream>
std::ifstream in("inaltime.in");
std::ofstream out("inaltime.out");

int n, v[102], m;

int f(int i, int niv)
{
    if(v[i] == 0)
        return niv;
    f(v[i], niv+1);
}

int main()
{
	in >> n;
	for(int i = 1; i <= n; i++)
		in >> v[i];
	for(int i = 1; i <= n; i++)
	{
		int l = f(i, 1);
		if(l > m)
			m = l;
	}
	out << m << " ";
}
