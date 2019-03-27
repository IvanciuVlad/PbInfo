#include <iostream>
#include <fstream>
using namespace std;
ifstream in("BFS.in");
ofstream out("BFS.out");
int ma[128][128],n,viz[128];
int c[128*128],li = 1,ls,m,start;
void put(int x){c[++ls] = x;}
void take(int &x){ x = c[li++];}
void bf(){
    put(start);
    viz[start] = 1;
    while(li <= ls)
    {
        int x;
        take(x);
        //out << x << " ";
        for(int i = 1; i <= n; ++i)
            if(ma[x][i] == 1 && !viz[i])
            {
                put(i);
                viz[i] = 1;
            }
    }
}
int main()
{
        in >> n >> m >> start;
        int x,y;
        for(int i = 1; i<= m; ++i)
        {
            in >> x >> y;
            ma[x][y] = ma[y][x] = 1;
        }
        bf();
        int i = 1;
        while(1)
        {
            if(c[i]){
                out << c[i] << "  ";
                i++;
            }
            else
                break;
        }
}