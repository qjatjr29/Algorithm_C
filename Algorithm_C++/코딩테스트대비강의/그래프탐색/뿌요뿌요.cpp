#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<vector<int> >map;
int blockCount,tempCount;
int MaxBlock=1;
bool visited[101][101];
bool can_go(int x,int y,int value)
{
    if(x<0 || x>=n || y<0 ||y>=n )return false;
    else if(visited[x][y]==true)return false;
    else if (map[x][y]!=value)return false;
    return true;
}
int dfs(int x,int y,int value)
{
    int Count=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(can_go(nx,ny,value))
        {
            visited[nx][ny]=true;
            tempCount+=dfs(nx,ny,value);
        }
    }
    return Count;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n;
    map=vector<vector<int> >(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==false)
            {
                tempCount=0;
                dfs(i,j,map[i][j]);
                if(tempCount>=4)
                {
                    blockCount++;
                }
                MaxBlock=max(MaxBlock,tempCount);
            }
        }
    }
    cout<<blockCount<<" "<<MaxBlock<<"\n";
    return 0;
}