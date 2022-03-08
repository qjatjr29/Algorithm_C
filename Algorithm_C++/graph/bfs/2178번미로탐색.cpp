#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

int N,M;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int answer;
vector<vector<char> > map;
vector<vector<bool> > visited;
void sol()
{
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(0,0),1));
    visited[0][0] = true;

    while(1)
    {
        if(q.empty()) break;
        int cx = q.front().first.first;
        int cy = q.front(). first.second;
        int cnt = q.front().second;
        q.pop();
        if(cx == N-1 && cy == M-1)
        {
            answer = min(answer,cnt);
            continue;
        }
        for(int i=0;i<4;i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >=N || ny <0 || ny >= M) continue;
            if(visited[nx][ny] || map[nx][ny]=='0') continue;
           
            visited[nx][ny] = true;
            q.push(make_pair(make_pair(nx,ny),cnt+1));
            
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;

    map = vector<vector<char> > (N,vector<char>(M,0));
    visited = vector<vector<bool> > (N,vector<bool>(M,false));
    for(int i=0;i<N;i++)
    {
        string s; 
        cin>>s;
        for(int j=0;j<M;j++)
        {
            map[i][j] = s[j];
        }
    }
    answer = INT_MAX;
    sol();
    cout<<answer<<"\n";
    return 0;
}