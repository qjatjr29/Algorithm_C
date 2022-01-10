#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m,r;
int items[101];
vector<vector<int>> adj;
int result;
// 한 노드에서 각 노드 까지 가는 cost 구하기.
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(adj[i][j]>adj[i][k]+adj[k][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
}
void getItem()
{
    floyd_warshall();
    for(int i=1;i<=n;i++)
    {
        int node_result=0;
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                node_result+=items[i];
            }
            else if(adj[i][j]<=m)
            {
                node_result+=items[j];
            }
        }
        result=max(result,node_result);
    }
   
        

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m>>r;
    adj=vector<vector<int>>(n+1,vector<int>(n+1,987654321));
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        items[i]=t;
    }
    for(int i=0;i<r;i++)
    {
        int locationA,locationB,cost;
        cin>>locationA>>locationB>>cost;
        adj[locationA][locationB]=cost;
        adj[locationB][locationA]=cost;
        
    }

    getItem();
    cout<<result<<"\n";


    return 0;
}