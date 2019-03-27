#include<fstream>
std::ifstream in("dslm.in");
std::ofstream out("dslm.out");
int m[21][21], viz[21][21], n, p, lmax, vmax[31], vc[31];

void cop()
{
	for(int i = 1; i <= lmax; i++)
		vmax[i] = vc[i];
}

void DSLM(int x, int l)
{
	l++;
	vc[l] = x;
	if(l > lmax)
		{
			lmax = l;
			cop();
		}
    for(int i = 1; i <= n; i++)
        {
		if(m[x][i] == 1 && !viz[x][i])
            {
            viz[x][i] = 1;	
			DSLM(i, l);
			viz[x][i] = 0;
			}
		
		}
}
int main()
{
	int a, b;
	in >> n >> p;
	while(in >> a >> b)
	{
		m[a][b] = 1;
	}
	DSLM(p, 0);	
	for(int i = 1; i <= lmax; i++)
		out << vmax[i] << " ";
}