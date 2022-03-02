#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int t;
int n,d,c;
vector<vector<pair<int,int> > > computers;
vector<int> dp;
void sol(int idx)
{
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,idx));
    dp[idx] = 0;
    while(1)
    {
        if(q.empty()) break;
        int cIdx = q.top().second;
        int cTime = -q.top().first;
        q.pop();
        
        // 이전에 현재 인덱스가 감염되는 경우 보다 이번 경우에 시간이 더 긴 경우 넘어감.
        if(cTime>dp[cIdx]) continue;
        for(int i=0;i<computers[cIdx].size();i++)
        {
            int nextIdx = computers[cIdx][i].second;
            int nextTime = cTime + computers[cIdx][i].first;

            if(nextTime < dp[nextIdx])
            {
                dp[nextIdx] = nextTime;
                q.push(make_pair(-nextTime,nextIdx));
            }
        }
    }
    int cnt = 0;
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i] != 987654321) 
        {
            cnt ++;
            answer = max(answer,dp[i]);
        }
    }
    cout<<cnt<<" "<<answer<<'\n';
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>t;

    for(int testcase = 0; testcase<t;testcase++)
    {
        cin>>n>>d>>c;
        dp = vector<int>(n+1,987654321);
        computers = vector<vector<pair<int,int> > >(n+1,vector<pair<int,int> >());
       
        int a,b,s;
        for(int i=0;i<d;i++)
        {
            cin>>a>>b>>s;
            computers[b].push_back(make_pair(s,a));
        }
       
        sol(c);
  
    }



    return 0;
}