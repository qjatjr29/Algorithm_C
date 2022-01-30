#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,k;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int maxPath=987654321;
vector<pair<int,int> > target;
vector<vector<int> >map;
vector<vector<int> >answer;
bool visited[101][101];
void bfs()
{
    queue<pair<int,pair<int,int> > > q;
    for(int i=0;i<target.size();i++)
    {
        int cx=target[i].first;
        int cy=target[i].second;
        q.push(make_pair(1,make_pair(cx,cy)));
        visited[cx][cy]=true;
        answer[cx][cy]=0;
    }
    while(1)
    {
        if(q.empty())break;
        int count=q.front().first;
        int curX=q.front().second.first;
        int curY=q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(nx<0 || nx>=n || ny<0 ||ny>=n )continue;
            else if(visited[nx][ny]) continue;
            else if(map[nx][ny]==0)
            {
                answer[nx][ny]=-1;
                continue;
            }
            //원래 있던 귤.
            else if(map[nx][ny]==1)
            {
                answer[nx][ny]=count;
                visited[nx][ny]=true;
                q.push(make_pair(count+1,make_pair(nx,ny)));
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>k;
    map=vector<vector<int> >(n+1,vector<int>(n+1,0));
    answer=vector<vector<int> >(n+1,vector<int>(n+1,-2));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==2)
            {
                target.push_back(make_pair(i,j));
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(answer[i][j]== -2 && map[i][j]==0)
            {
                cout<<-1<<" ";
            }
            else cout<<answer[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}