#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

ifstream in("regine1.in");
ofstream out("regine1.out");

int s[100],n;

void scrie()
{
for(int k = 1; k <= n; ++k){
  for(int i = 1; i <= n; ++i)
    if( s[k] == i)
        cout <<"*";
    else
        cout <<"-";
  cout << endl;
}
}
int  valid(int k)
{
  for(int i = 1; i <k ; ++i)
    if(s[i] == s[k]|| k-i == abs(s[k]-s[i]))
    	return 0;
    return 1;

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
    {
      if( k == n)
      {
        scrie();
        k = 0;
      }
      else
      {

        s[++k] = 0;
      }
    }
    else
      k--;
  }
}
int main(){
  cin >> n;
  bkt();
}
