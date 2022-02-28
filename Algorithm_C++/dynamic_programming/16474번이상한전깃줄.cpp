#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int N,M,K;
int leftSide[2001];
int rightSide[2001];
int adj[2001][2001];
int dp[2001][2001];
int sol()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(adj[i][j] == 1)
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return K-dp[N][M];
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;

    int number;
    for(int i=1;i<=N;i++)
    {
        cin>>number;
        leftSide[number] = i;
    }
    for(int i=1;i<=M;i++)
    {
        cin>>number;
        rightSide[number] = i;
    }

    cin>>K;
    
    for(int i=0;i<K;i++)
    {
        int s,e;
        cin>>s>>e;
        adj[leftSide[s]][rightSide[e]] = 1;
    }
    cout<<sol()<<"\n";
    return 0;
}