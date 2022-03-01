#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<vector<int> > map;
int answer,result;
int cnt;
bool visited[501][501];
void sol(int x, int y)
{
    visited[x][y] = true;
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || ny <=0 || nx>n || ny>m) continue;
        if(visited[nx][ny] == true) continue;
        if(map[nx][ny]==1)
        {
            cnt++;
            sol(nx,ny);
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m;
    map = vector<vector<int> >(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]==1 && visited[i][j]==false)
            {
                result++;
                cnt = 1;
                sol(i,j);
                answer = max(answer,cnt);
            }
        }
    }
    cout<<result<<"\n";
    cout<<answer<<"\n";
    return 0;
}
