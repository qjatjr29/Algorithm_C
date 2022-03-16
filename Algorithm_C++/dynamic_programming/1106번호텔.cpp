#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int C,N;
pair<int,int> cities[21];
int dp [1101];
int answer;
void setDP()
{
    for(int i=1;i<=1100;i++)
    {
        dp[i] = 987654321;
    }
    dp[0] = 0;
    for(int i=0;i<N;i++)
    {
        int people = cities[i].second;
        int weight = cities[i].first;
        for(int j=people;j<=1100;j++)
        {
            dp[j] = min(dp[j],dp[j-people]+weight);
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>C>>N;
    for(int i=0;i<N;i++)
    {
        int cost,custom;
        cin>>cost>>custom;
        cities[i] = make_pair(cost,custom);
    }
    setDP();
    answer = dp[C];
    for(int i=C;i<=1100;i++)
    {
        answer = min(answer,dp[i]);
    }
    cout<<answer<<"\n";

    return 0;
}