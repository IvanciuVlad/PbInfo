#include<iostream>
using namespace std;

int main()
{
  int n, k = 0;
  cin >> n;
  while(n)
  {
    if(n % 2 == 0)
      k++;
    cin >> n;
  }
  if(k)
    cout << k;
  else
    cout << "NU EXISTA";
  return 0;
}