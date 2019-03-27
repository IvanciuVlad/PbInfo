#include<fstream>
using namespace std;
ifstream in("izolate.in");
ofstream out("izolate.out");
int n, v[101], m;

int main()
{
	int x, y;
	in >> n;
	m = n;
	while (in >> x >> y)
	{
		if (!v[x])
		{
			v[x] = 1;
			m--;
		}
		if (!v[y])
		{
			v[y] = 1;
			m--;
		}
	}
	out << m << " ";
	for (int i = 1; i <= n; i++)
		if (!v[i])
			out << i << " ";
	in.close();
	out.close();
	return 0;
}
