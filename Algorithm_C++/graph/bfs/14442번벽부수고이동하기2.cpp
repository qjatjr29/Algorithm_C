#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

int N,M,K;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int answer[1001][1001];
vector<vector<char> > map;
bool visited[1001][1001][11];
void sol()
{
    queue<pair<int,pair<int,int> > > q;
    q.push(make_pair(0,make_pair(0,0)));
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            answer[i][j]= INT_MAX;
        }
    }
    answer[0][0] = 1;
    while(1)
    {
        if(q.empty()) break;
        int wall = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        
        if(cx == N-1 && cy == M-1) return;

        for(int i=0;i<4;i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx>=N || ny >= M) continue;
           
            if(map[nx][ny] == '1' && wall+1<=K)
            {
                if(visited[nx][ny][wall+1] == false)
                {
                    visited[nx][ny][wall+1] = true;
                    q.push(make_pair(wall+1,make_pair(nx,ny)));
                    answer[nx][ny] = answer[cx][cy] + 1;  
                }
            }
            if(map[nx][ny] == '0' && visited[nx][ny][wall]==false)
            {
                visited[nx][ny][wall] = true;
                q.push(make_pair(wall,make_pair(nx,ny)));
                answer[nx][ny] = answer[cx][cy] + 1;  
            }
        }

    }

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M>>K;
    map = vector<vector<char> >(N+1,vector<char>(M+1));
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<M;j++)
        {
            map[i][j] = s[j];
        }
    }

    sol();
    if(answer[N-1][M-1] == INT_MAX) cout<<-1<<'\n';
    else cout<<answer[N-1][M-1]<<"\n";

    return 0;
}