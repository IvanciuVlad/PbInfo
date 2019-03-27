#include<fstream>
using namespace std;
ifstream f("proiecte.in");
ofstream g("proiecte.out");

int n, t[1001], s[1001];

void citire()
{
  f >> n; 
  for(int i = 1; i <= n; i++)
  {
    f >> t[i];
    s[i] = i;
  }
}

void sort()
{
  for(int i = 1; i < n; i++)
    for(int j = i + 1; j <= n; j++)
   		 if(t[i] > t[j])
  {
    swap(s[i], s[j]);
    swap(t[i], t[j]);
  }
}

int main()
{
  citire();
  sort();
  for(int i = 1; i <= n; i++)
    g << s[i] << " ";
  return 0;
}