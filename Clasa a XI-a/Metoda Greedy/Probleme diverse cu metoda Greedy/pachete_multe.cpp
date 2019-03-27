#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
ifstream in("pachete_multe.in");
ofstream out("pachete_multe.out");

struct jump{
	int f,t;
	jump(){}
	jump(int _f, int _t) : f(_f), t(_t) {}
};

int n, v[100010], m, p[100010];
jump w[200000];


int main() {
	in>>n;
	int i,j,k,last = n + 1;
	for(i =1; i<=n;++i){
		in>>v[i];
		p[v[i]] = i;
	}
	for(k = 1; k<=n;++k) {
		if(v[k] == k)
			continue;
		if(last != k) {
			v[last] = v[k];
			p[v[k]] = last;
			w[m++]= jump(k,last);
			last = k;
		}
		/*
		for(j = k + 1; j<=n;++j)
			if(v[j]==k)
				break;
		*/
		j=p[k];
		v[last] = v[j];
		p[v[j]] = last;
		w[m++]= jump(j,last);
		last = j;
	}
	out<<m<<"\n";
	for(i = 0;i<m;++i)
		out<<w[i].f <<" "<<w[i].t<<"\n";
	return 0;
}