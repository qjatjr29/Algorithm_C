#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

int T;
int N,M,K;
// 각 공항에 도착하는데 필요한 비용에 대한 소요시간.
// 공항 - 비용 => 소요시간.
int dp[101][10001];
int answer;
struct Ticket{
    int arrive;
    int cost;
    int time;
};
vector<vector<Ticket> > tickets;
void sol()
{
    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(0,1)));
    dp[1][0] = 0;
    while(1)
    {
        if(pq.empty()) break;
        int cTime = -pq.top().first;
        int cCost = pq.top().second.first;
        int cidx = pq.top().second.second;
        pq.pop();

        // 이미 현재 비용으로 공항에 가는 방법이 더 적은 경우가 있는 경우.
        if(dp[cidx][cCost]<cTime) continue;

        for(int i=0;i<tickets[cidx].size();i++)
        {
            int next = tickets[cidx][i].arrive;
            int nextCost = tickets[cidx][i].cost + cCost;
            int nextTime = tickets[cidx][i].time + cTime;

            // 여행비 넘어가는 경우
            if(nextCost > M) continue;
            // 다음 공항으로 가는 경우가 이미 시간이 덜 걸릴 때.
            if(dp[next][nextCost] <= nextTime )continue;

            // 현재 시간이 다음 공항으로 가는 시간보다 덜 걸릴때
            // 현재 비용보다 큰 비용으로 다음 공항으로 가는 최소 시간이
            // 현재 시간보다 크다면 최소시간을 변경해 준다.
            // ( 현재 비용으로 최소시간을 갈 수 있기 때문 )
            for(int j=nextCost;j<=M;j++)
            {
                if(dp[next][j] > nextTime) dp[next][j] = nextTime;
            }
            pq.push(make_pair(-nextTime,make_pair(nextCost,next)));
        }
    }

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>T;
    for(int testcase = 0;testcase<T;testcase++)
    {
        cin>>N>>M>>K;
        tickets = vector<vector<Ticket> >(N+1, vector<Ticket>());
        for(int i=0;i<K;i++)
        {
            int start, end, c, d;
            cin>>start>>end>>c>>d;
            Ticket t = {end,c,d};
            tickets[start].push_back(t);
        }
         answer = INT_MAX;
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<10001;j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        sol();
        for(int i =1;i<=M;i++)
        {
            answer = min(answer,dp[N][i]);
        }
        if(answer == INT_MAX) cout<<"Poor KCM"<<"\n";
        else cout<<answer<<"\n";
    }
   
    return 0;
}
