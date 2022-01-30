#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int maxPath=987654321;
vector<vector<int> >map;
bool visited[101][101];
void bfs()
{
    queue<pair<int,pair<int,int> > > q;
    q.push(make_pair(0,make_pair(0,0)));
    visited[0][0]=true;
    while(1)
    {
        if(q.empty())break;
        int count=q.front().first;
        int curX=q.front().second.first;
        int curY=q.front().second.second;
        q.pop();
        if(curX==n-1 && curY==m-1)
        {
            maxPath=min(maxPath,count);
            continue;
        }
        for(int i=0;i<4;i++)
        {
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(nx<0 || nx>=n || ny<0 ||ny>=m )continue;
            else if(visited[nx][ny]) continue;
            else if(map[nx][ny]==0) continue;
            visited[nx][ny]=true;
            q.push(make_pair(count+1,make_pair(nx,ny)));
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m;
    map=vector<vector<int> >(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }
    bfs();
    if(maxPath==987654321) cout<<-1<<"\n";
    else cout<<maxPath<<"\n";
    return 0;
}