#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

int N;
vector<pair<int,int> > lines;
int dp[101];
int sol()
{
    int res = INT_MIN;
    
    for(int i=1;i<=N;i++)
    {
        dp[i] = 1;
        for(int j = 1;j<i;j++)
        {
            if(lines[j].second < lines[i].second)
            {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        res = max(res,dp[i]);
    }
    return res;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    lines = vector<pair<int,int> > (N+1);
    for(int i=1;i<=N;i++)
    {
        int start,end;
        cin>>start>>end;
        lines[i]=make_pair(start,end);
    }
    sort(lines.begin(),lines.end());

    int cnt = sol();
    int answer ;
    if(cnt != INT_MIN)
    {
        answer = N - cnt;
        cout<<answer<<"\n";
    }
    else cout<<0<<"\n";
    
    
    return 0;
}