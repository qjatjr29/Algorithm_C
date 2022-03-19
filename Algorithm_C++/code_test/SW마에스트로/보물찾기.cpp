#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int N; // 정점의 개수
int M; // 보물의 개수
// 모험은 1번 정점에서 시작.
vector<vector<pair<int,int> > > adj;
bool visited[100001];
int treasure[100001];
pair<int,int> answer;
void adventure(int index,int curCost)
{
    cout<<index<< " : "<< curCost<<"\n";
    if(treasure[index]!=0)
    {
        if(answer.second == treasure[index]-(curCost*2))
        {
            answer.first = min(answer.first,index);
        }
        else if(answer.second < treasure[index]-(curCost*2))
        {
            answer = make_pair(index,treasure[index]-(curCost*2));
        }
    }
    for(int i=0;i<adj[index].size();i++)
    {
        int next = adj[index][i].first;
        int nextCost = curCost + adj[index][i].second;
        if(visited[next] == true) continue;
        visited[next] = true;
        adventure(next,nextCost);
        visited[next] = false;
    }
    // for(int i=1;i<=N;i++)
    // {
    //     for(int j=1;j<=N;j++)
    //     {
    //         for(int z=1;z<=N;z++)
    //         {
    //             dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k]);
    //         }
    //     }
    // }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;
    adj = vector<vector<pair<int,int> > >(N+1,vector<pair<int,int> >());
    for(int i=0;i<N-1;i++)
    {
        int node1,node2,cost;
        cin>>node1>>node2>>cost;
        adj[node1].push_back(make_pair(node2,cost));
        adj[node2].push_back(make_pair(node1,cost));
    }

    for(int i=0;i<M;i++)
    {
        int node,value;
        cin>>node>>value;
        treasure[node] = value;
    }

    answer.first = INT_MAX;
    visited[1] = true;
    adventure(1,0);
    cout<<answer.first<<" "<<answer.second<<"\n";

    return 0;
}