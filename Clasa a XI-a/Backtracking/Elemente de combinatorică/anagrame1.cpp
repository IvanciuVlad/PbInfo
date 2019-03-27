#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;

int s[100], n;
char a[100];
ifstream f("anagrame1.in");
ofstream g("anagrame1.out");

void scrie()
{
  int i;
  for(i = 1; i <= n; i++)
    g << a[s[i] - 1];
  g << endl;
}

int valid(int k)
{
  int i;
  for(i = 1; i < k; i++)
    if(s[k] == s[i])
    	return 0;
  return 1;
}

void sort()
{
	sort(a, a+n);
}

void bkt()
{
  int k = 1, up;
  s[k] = 0;
  while(k)
  {
    up = 0;
   	while(!up && s[k] < n)
    {
      s[k]++;
      if(valid(k))
        up = 1;
    }
    if(up)
      if(k == n)
      	scrie();
      else
    {
      k++;
      s[k] = 0;
    }
    else
      k--;
  }
}  

int main()
{
  f >> a;
  n = strlen(a);
  sort();
  bkt();
  return 0;
}
