#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX_NUM = 987654321;
int n, m;
vector<pair<int,int> > adj[201];
int cost[201];
int preNode[201][201];
int dp[201][201];


void setting()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        dp[start][end]=cost;
        dp[end][start]=cost;
        preNode[start][end]=end;
        preNode[end][start]=start;
    }
    
}
// floyd_warshall algorithm
void floyd_warshall()
{
    // k : 거쳐가는 노드
    for(int k=1;k<=n;k++)
    {
        // i = 출발 정점
        for(int i=1;i<=n;i++)
        {
            // j = 도착 정점
            for(int j=1;j<=n;j++)
            {
                if(dp[i][k]+dp[k][j]<dp[i][j])
                {
                    dp[i][j]=dp[i][k]+dp[k][j];
                    preNode[i][j]=preNode[i][k];
                }
            }
        }
    }
}
void parcel()
{
    for(int i=0;i<201;i++)
    {
        for(int j=0;j<201;j++)
        {
            if(i==j)dp[i][j]=0;
            else dp[i][j]=MAX_NUM;
        }
    }
    setting();
    floyd_warshall();
    
    // for(int i=1;i<=n;i++)
    // {
    //     cost[i]=MAX_NUM;
    // }
    // priority_queue<pair<int, int> > pq;
    // cost[index]=0;
    // pq.push(make_pair(0, index));

    // while (1)
    // {
    //     if (pq.empty())
    //         break;
    //     int curCost = -pq.top().first;
    //     int curIndex = pq.top().second;
    //     pq.pop();
    //     // 이미 최단 경로가 아님.
    //     if(cost[curIndex]<curCost)continue;
        
    //     for (int i = 0; i < adj[curIndex].size(); i++)
    //     {   
    //         int nextIndex = adj[curIndex][i].first;
    //         int nextCost = adj[curIndex][i].second + curCost;
    //         if(cost[nextIndex]>nextCost)
    //         {
    //             preNode[nextIndex]=curIndex;
    //             cost[nextIndex]=nextCost;
    //             pq.push(make_pair(-nextCost,nextIndex));
    //         }
    //     }
    // }
    // for(int i=1;i<=n;i++)
    // {
    //     if(i==index)cout<<"- ";
    //     else if(preNode[i]==index)cout<<i<<" ";
    //     else
    //     {
    //         int here=i;
    //         while(1)
    //         {
    //             if(preNode[here]==index)
    //             {
    //                 cout<<here<<" ";
    //                 break;
    //             }
    //             else here=preNode[here];
    //         }
    //     }
    // }
    // cout<<"\n";
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    parcel();  
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) cout<<"- ";
            else cout<<preNode[i][j]<<" ";
        }
        cout<<"\n";
    }  
    return 0;
}