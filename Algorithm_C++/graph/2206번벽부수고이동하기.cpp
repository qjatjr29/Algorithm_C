#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N,M;
vector<vector<char> > map;
bool visited[1001][1001][2];
int answer[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void sol()
{
    queue<pair<pair<int,int>,int > > pq;
    pq.push(make_pair(make_pair(1,1),0));
    visited[1][1][0] = true;
    visited[1][1][1] = true;
    while(1)
    {
        if(pq.empty()) break;
        int cx = pq.front().first.first;
        int cy = pq.front().first.second;
        int wall = pq.front().second;
        pq.pop();
        if(cx == N && cy == M) 
        {
            //cout<<answer[cx][cy]<<"\n";
            return;
        }
        for(int i=0;i<4;i++)
        {   
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx <= 0 || nx > N || ny <= 0 || ny > M )continue;
            // 다음이 벽이고 부순적 없는 경우
            if(map[nx][ny] == '1' && wall == 0)
            {
                if(visited[nx][ny][1] == false)
                {
                    visited[nx][ny][1] = true;
                    answer[nx][ny] = answer[cx][cy] + 1;
                    pq.push(make_pair(make_pair(nx,ny),1));
                }
            }
            // 이동 가능할 때
            if(map[nx][ny] != '1' && visited[nx][ny][wall]==false)
            {
                visited[nx][ny][wall] = true;
                answer[nx][ny] = answer[cx][cy] + 1;
                pq.push(make_pair(make_pair(nx,ny),wall));
            }
        }


    }

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    map = vector<vector<char> >(N+1,vector<char>(M+1,0));
    
    for(int i=1;i<=N;i++)
    {
        string r;
        cin>>r;
        for(int j=1;j<=r.size();j++)
        {
            map[i][j] = r[j-1];
        }
    }
    answer[1][1] = 1;
    if(N==1 && M==1) 
    {
        cout<<1<<"\n";
    }
    else
    {
        answer[N][M] = INT_MAX;
        sol();
        //sol(0,0,0,1);
        if(answer[N][M] == INT_MAX)
        {
            cout<<-1<<"\n";
        }
        else cout<<answer[N][M]<<"\n";
    }
    return 0;
}