#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N;
string star[3]={"  *  "," * * ","*****"};
vector<vector<char> > map;
void divideConquer(int x,int y,int size)
{
    if(size==3)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<5;j++)
            {
                map[x+i][y+j]=star[i][j];
            }
        }
        return ;
    }
    // up
    divideConquer(x,y+(size/2),size/2);
    // leftdown
    divideConquer(x+(size/2),y,size/2);
    // rightdown
    divideConquer(x+(size/2),y+size,size/2);
}
int main()
{   
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    map=vector<vector<char> >(N,vector<char>(N*2,' '));
    divideConquer(0,0,N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N*2;j++)
        {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
    return 0;
}