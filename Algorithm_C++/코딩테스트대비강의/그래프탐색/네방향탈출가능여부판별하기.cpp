#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int map[101][101];
bool visited[101][101];
queue<pair<int,int> > nodes;
bool chk;
bool can_go(int x,int y)
{
    if(x<0 || x>=n ||y<0 ||y>=m) return false;
    else if(visited[x][y]==true) return false;
    else if(map[x][y]==0)return false;
    return true;
}
void bfs()
{
    nodes.push(make_pair(0,0));
    visited[0][0]=true;
    while(1)
    {
        if(nodes.empty())break;
        int curX=nodes.front().first;
        int curY=nodes.front().second;
        
        if(curX==n-1 && curY==m-1)
        {
            chk=true;
            break;
        }
        nodes.pop();

        for(int i=0;i<4;i++)
        {
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(can_go(nx,ny))
            {
                visited[nx][ny]=true;
                nodes.push(make_pair(nx,ny));
            }
        }    


    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int state;
            cin>>state;
            map[i][j]=state;
        }
    }
    bfs();
    if(chk)cout<<1<<"\n";
    else cout<<0<<"\n";

    return 0;
}