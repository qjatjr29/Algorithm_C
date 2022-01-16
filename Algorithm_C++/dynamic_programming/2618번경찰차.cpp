#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int N, W;

// 사건이 발생한 장소들 모음.
vector<pair<int, int> > accident;

// dp[a][b] - police1 이 a 사건, police2가 b를 최신에 처리했을때의 거리.
int dp[1001][1001];

// 사건과 경찰차 사이 거리 구하는 함수
int calDistance(int policeX, int policeY, int index)
{
    int accidentX = accident[index].first;
    int accidentY = accident[index].second;
    int dist = abs(policeX - accidentX) + abs(policeY - accidentY);
    return dist;
}
int dispatch(int police1, int police2)
{
    // 이미 마지막 사건 까지 도착.
    if (police1 == W || police2 == W)
        return 0;
    // 이미 확인한 공간.
    if (dp[police1][police2] != -1)
        return dp[police1][police2];

    // 다음 사건 번호.
    int nextAccident = max(police1, police2) + 1;
    int dist1, dist2;

    // 첫 번째 경찰차
    // 처음 출발하는 경우
    if (police1 == 0)
    {
        dist1 = calDistance(1, 1, nextAccident);
    }
    else
        dist1 = calDistance(accident[police1].first, accident[police1].second, nextAccident);

    // 두 번째 경찰차
    // 처음 출발하는 경우
    if (police2 == 0)
    {
        dist2 = calDistance(N, N, nextAccident);
    }
    else
        dist2 = calDistance(accident[police2].first, accident[police2].second, nextAccident);

    //cout<<"dist1  : "<<dist1<<" dist2 : "<<dist2<<'\n';
    int firstPath = dist1 + dispatch(nextAccident, police2);
    int secondPath = dist2 + dispatch(police1, nextAccident);

    dp[police1][police2] = min(firstPath, secondPath);
    return dp[police1][police2];
}
void route(int police1, int police2)
{
    if (police1 == W || police2 == W)
        return;

    int next = max(police1, police2) + 1;

    int dist1, dist2;
    // 첫 번째 경찰차
    // 처음 출발하는 경우
    if (police1 == 0)
    {
        dist1 = calDistance(1, 1, next);
    }
    else
        dist1 = calDistance(accident[police1].first, accident[police1].second, next);

    // 두 번째 경찰차
    // 처음 출발하는 경우
    if (police2 == 0)
    {
        dist2 = calDistance(N, N, next);
    }
    else
        dist2 = calDistance(accident[police2].first, accident[police2].second, next);

    // 첫 번째 경찰차가 움직인 경우가 더 짧은 경우.
    if (dp[next][police2] + dist1 < dp[police1][next] + dist2)
    {
        cout << 1 << "\n";
        route(next, police2);
    }
    else
    {
        cout << 2 << "\n";
        route(police1, next);
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> N >> W;

    accident=vector<pair<int,int> >(W+1);
    memset(dp,-1,sizeof(dp));
    // 사건 위치 저장
    for (int i = 1; i <= W; i++)
    {
        int wX, wY;
        cin >> wX >> wY;
        accident[i]=make_pair(wX, wY);
    }

    cout << dispatch(0, 0) << "\n";
    route(0, 0);
    return 0;
}
