#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int dx[2]={1,0};
int dy[2]={0,1};
int result;
vector<vector<int> >map;
vector<vector<bool> > visited;
bool can_go(int x,int y)
{
    if(x<0 && x>=n && y<0 && y>=m) return false;
    else if(visited[x][y]==true)return false;
    else if(map[x][y]==0)return false;
    else return true;
}
void dfs(int x,int y)
{
    if(x==n-1 && y==m-1)
    {
        result=1;
        return;
    }
    for(int i=0;i<2;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(can_go(nx,ny))
        {
            visited[nx][ny]=true;
            dfs(nx,ny);
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m;
    map=vector<vector<int> >(n+1,vector<int>(m+1,0));
    visited=vector<vector<bool> >(n+1,vector<bool>(m+1,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int state;
            cin>>state;
            map[i][j]=state;
        }
    }
    visited[0][0]=true;
    dfs(0,0);
    cout<<result<<"\n";
    return 0;
}