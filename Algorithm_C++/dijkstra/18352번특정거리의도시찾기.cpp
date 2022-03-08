#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;

int N,M,K,X;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> answer;
void sol()
{
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,X));
    visited[X] = true;

    while(1)
    {
        if(pq.empty()) break;
        int cx = pq.top().second;
        int cnt = -pq.top().first;
        pq.pop();
        if(cnt == K)
        {
            answer.push_back(cx);
            continue;
        }
        for(int i=0;i<adj[cx].size();i++)
        {
            int nx = adj[cx][i];
            if(visited[nx]) continue;
            visited[nx] = true;
            if(cnt + 1 == K)
            {
                answer.push_back(nx);
            }
            else pq.push(make_pair(-(cnt+1),nx));
        }
    }
    if(answer.size()==0)
    {
        cout<<-1<<"\n";
    }
    else
    {
        sort(answer.begin(),answer.end());
        for(int i=0;i<answer.size();i++)
        {
            cout<<answer[i] << "\n"; 
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M>>K>>X;
    adj = vector<vector<int> > (N+1,vector<int>());
    visited = vector<bool>(N+1,false);
    for(int i=0;i<M;i++)
    {
        int city1,city2;
        cin>>city1>>city2;
        adj[city1].push_back(city2);
    }
    sol();

    return 0;
}