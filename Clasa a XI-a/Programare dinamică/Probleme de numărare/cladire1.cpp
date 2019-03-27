#include<fstream>
using namespace std;
ifstream f("cladire1.in");
ofstream g("cladire1.out");

int n, m, a[1001][1001], d = 9901;

int main() 
{
	int i, j, k;
	f >> n >> m >> k;
	while(k--)
    {
		f >> i >> j;
		a[i][j] = -1;
	}
	for(i = 1; i <= n; ++i)
		if(a[i][1] != -1)
			a[i][1] = 1;
		else
			break;
	
	for(j = 1; j <= m; ++j)
		if(a[1][j] != -1)
			a[1][j] = 1;
		else
			break;
	
	for(i = 2; i <= n; ++i)
		for(j = 2; j <= m; ++j){
			if(a[i][j] == -1)
				continue;
			if(a[i][j-1] > 0)
				a[i][j] += a[i][j-1];
			if(a[i-1][j] > 0)
				a[i][j] += a[i-1][j];
			a[i][j] %= d;
		}
	

	g << a[n][m];
	return 0;
}
