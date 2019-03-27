#include<iostream>
#include<iomanip>
using namespace std;

float x, y, z, m;
int main()
{
    cin >> x >> y >> z;
    m = (x + y + z)/3.0;
    if(m == int(m))
        cout << setprecision (2) << fixed << m;
    else
    {
        m *= 100;
        m = int(m);
        m = float(m);
        m /= 100.0;
        cout << setprecision (2) << fixed << m;
    }
}