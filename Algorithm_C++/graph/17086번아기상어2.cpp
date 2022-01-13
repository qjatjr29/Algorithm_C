#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N,M;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,1,-1,-1,0,1};
vector<vector<bool>> visited;
vector<vector<int>> map;
int result;
void bfs(int x,int y)
{
    queue<pair<int,pair<int,int>>> pq;
    visited=vector<vector<bool>>(N+1,vector<bool>(M+1,false));
    pq.push(make_pair(0,make_pair(x,y)));
    visited[x][y]=true;
    while(1)
    {
        if(pq.empty())break;
        int curX=pq.front().second.first;
        int curY=pq.front().second.second;
        int curCount=pq.front().first;
        pq.pop();
        if(map[curX][curY]==1)
        {
            result=max(result,curCount);
            return;
        }

        for(int i=0;i<8;i++)
        {
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && visited[nx][ny]==false)
            {
                visited[nx][ny]=true;
                pq.push(make_pair(curCount+1,make_pair(nx,ny)));
            }
        }

    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;
    map=vector<vector<int>>(N+1,vector<int>(M+1,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int state;
            cin>>state;
            map[i][j]=state;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(map[i][j]==0)
            {
                bfs(i,j);
            }
        }
    }
    cout<<result<<"\n";
    return 0;
}