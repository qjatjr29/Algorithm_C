#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N,M;
vector<vector<int> > adj;
vector<bool> visited;
int ans=-1;
void sol(int index)
{
    visited[index]=true;
    ans++;
    for(int i=0;i<adj[index].size();i++)
    {
        int nidx=adj[index][i];
        if(visited[nidx]==false)
        {
            sol(nidx);
        }
    }
    
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;
    adj=vector<vector<int> >(N+1,vector<int>());
    visited=vector<bool>(N+1,false);
    for(int i=0;i<M;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    sol(1);
    cout<<ans<<"\n";
    return 0;
}