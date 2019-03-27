#include<fstream>
std::ifstream in("preordine1.in");
std::ofstream out("preordine1.out");


int v[1000], x, k1, k2, n, ok;

int main()
{
	while(in >> x && !ok)
	{
		if(x == 0)
			k1++;
		else
			k2++, v[++n] = x;
		if(k1 == k2)
			ok = 1;
	}
	
	for(int i = 2; i <= n; i++)
		out << v[i] << " ";
}