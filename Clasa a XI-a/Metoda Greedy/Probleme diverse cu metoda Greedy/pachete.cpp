#include <iostream>
#include <fstream>
using namespace std;
ifstream in("pachete.in");
ofstream out("pachete.out");
int n,v[104],mutari[1005][2],nr = 0, zero ;

int main()
{
    in >> n;
    for(int i = 1; i <= n; i++)
        in >> v[i];

    zero = n + 1;
    for(int pos = 1; pos <= n; ++pos)
        if(pos != v[pos])
        {

            nr++;


            v[zero] = v[pos];
            v[pos] = 0;


            mutari[nr][0] = pos;
            mutari[nr][1] = zero;


            for(int i = 1; i <= n + 1; ++i)
                if(pos == v[i])
                {

                    v[pos] = v[i];
                    nr++;

                    mutari[nr][0] = i;
                    mutari[nr][1] = pos;

                    if(i == v[zero])
                    {
                        v[i] = v[zero];
                        v[zero] = 0;
                        nr++;

                        mutari[nr][0] = zero;
                        mutari[nr][1] = i;

                    }
                    else
                    {

                        v[i] = 0;

                        zero = i;
                    }

                    pos = 1;

                    break;
                }
        }
    out << nr << endl;
    for(int i = 1; i <= nr; ++i)
        out << mutari[i][0] << " " << mutari[i][1] << endl;

}