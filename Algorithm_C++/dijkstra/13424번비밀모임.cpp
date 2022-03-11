#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;

int T,N,M,K;
vector<vector<pair<int,int> > > adj;
int dp[101][101];
vector<int> friends;
pair<int,int> answer;
void calcPath()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                dp[j][k] = min(dp[j][k],dp[j][i] + dp[i][k]);
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>T;
    for(int testcase = 0; testcase < T;testcase++)
    {
        cin>>N>>M;
        adj = vector<vector<pair<int,int> > >(N+1,vector<pair<int,int> >());
        
        friends.clear();
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                if(i==j) continue;
                dp[i][j] = 987654321;
            }
        }
        for(int i=0;i<M;i++)
        {
            int room1,room2,cost;
            cin>>room1>>room2>>cost;
            dp[room1][room2] = cost;
            dp[room2][room1] = cost;
        }
        cin>>K;
        for(int i=0;i<K;i++)
        {
            int friendRoom;
            cin>>friendRoom;
            friends.push_back(friendRoom);
        }
        calcPath();
        answer.second = 987654321;
        answer.first = 0;
        for(int i=1;i<=N;i++)
        {
            int temp = 0;
            for(int j=0;j<friends.size();j++)
            {
                int idx = friends[j];
                temp += dp[idx][i];
            }
            if(answer.second > temp)
            {
                answer = make_pair(i,temp);
            }
        }
        cout<<answer.first<<"\n";
    }


    return 0;
}