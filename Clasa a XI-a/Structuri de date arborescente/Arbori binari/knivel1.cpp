#include<fstream>
#include<iostream>
std::ifstream in("knivel1.in");
std::ofstream out("knivel1.out");

int sum, k;

struct nod{
    int info;
    nod * st, *dr;
};

void citire(nod * & p)
{
    int x;
    in >> x;
    if(x == 0)
        p = NULL;
    else
    {
        p = new nod;
        p -> info = x;
        citire(p -> st);
        citire(p -> dr);
    }
}

void preordine(nod * p, int niv)
{
	if(p != NULL)
	{
		if(niv == k-1)
			sum += p -> info;
		preordine(p -> st, niv+1);
		preordine(p -> dr, niv+1);
	}
}

int main()
{
	nod *p = NULL;
	citire(p);
	in >> k;
	preordine(p -> st, 0);
	preordine(p -> dr, 0);
	out << sum;
}