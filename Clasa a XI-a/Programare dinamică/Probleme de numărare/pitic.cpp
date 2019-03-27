#include<fstream>

using namespace std;

ifstream in("pitic.in");
ofstream out("pitic.out");

long long n, m, a[44][44];

int main()
{
	in >> n >> m;
	a[1][1] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			a[i][j] += a[i-1][j-1]+a[i-1][j]+a[i-1][j+1];
	}
	
	/*for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			out << a[i][j] << " ";
		out << endl;
	}*/
	out << a[m][1];// << " " << a[1][m];
}