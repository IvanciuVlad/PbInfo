#include <fstream> 
#include <set>
using namespace std;
ifstream cin("bipartit2.in");
ofstream cout("bipartit2.out");

int a[128][128], viz[128], n, ok = 1, col[128], m;
set <int> s1, s2;

void read() {
	int x, y;
	cin >> n >> m;
	while(m--) {
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
}

void dfs(int x, int c) {
	if(!ok)
		return;
	col[x] = c;
	c *= -1;
	viz[x] = 1;
	for(int i = 1; i <= n; ++i)
		if(a[x][i]) {
			if(viz[i]) {
				if(col[i] != c) {
					ok = 0;
				}
			} else {
				dfs(i, c);
			}
		}
}

int main() {
	read();
	for(int i = 1; i <= n; ++i)
		if(!viz[i])
			dfs(i, 1);
	cout << (ok ? "DA\n" : "NU\n");
	if(ok) {
		for(int i = 1; i <= n; ++i)
			if(col[i] == col[1])
				s1.insert(i);
			else
				s2.insert(i);
		set <int> :: iterator it;
		for(it = s1.begin(); it != s1.end(); ++it)
			cout << *it << " ";
		cout << "\n";
		for(it = s2.begin(); it != s2.end(); ++it)
			cout << *it << " ";
	}
}