#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int N,M;
vector<vector<int> > adj;
vector<bool>  visited;
bool answer;
void chk(int idx,int cnt)
{
    if(cnt == 4) 
    {
        cout<<1<<"\n";
        exit(0);
    }
    for(int i=0;i<adj[idx].size();i++)
    {
        int nx = adj[idx][i];
        if(visited[nx] == false)
        {
            visited[idx] = true;
            chk(nx,cnt + 1);
            visited[idx] = false;
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;
    adj = vector<vector<int> >(N+1,vector<int>());
    visited = vector<bool>(N+1,false);
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<N;i++)
    {
        visited = vector<bool>(N+1,false);
        chk(i,0);
    }
    cout<<0<<"\n";
    return 0;
}