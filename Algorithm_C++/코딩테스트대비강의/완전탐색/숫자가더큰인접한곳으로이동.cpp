#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, startx,starty;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<vector<int> > map;
void move(int x,int y)
{
    int maxNum=map[x][y];
    cout<<maxNum<<" ";
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>0 && nx<=n && ny>0 && ny<=n)
        {
            if(maxNum<map[nx][ny])
            {
                return move(nx,ny);
                break;
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>startx>>starty;
    map=vector<vector<int> >(n+1,vector<int>(n+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int number;
            cin>>number;
            map[i][j]=number;
        }
    }
    move(startx,starty);
    cout<<"\n";

    return 0;
}
