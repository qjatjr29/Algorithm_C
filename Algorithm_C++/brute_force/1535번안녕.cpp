#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int lost[21];
int enjoy[21];
int dp[101];
int sol(int index,int hp,int joy)
{
    // 기저사례
    if(hp<=0) return 0;
    // 범위 넘어가면 끝.
    if(index>=N) return joy;
    // 현재 것을 안 쓰는 경우
    // 현재 것 써서 hp 깍고 들어 간 경우
    // 중 최대
    return max(sol(index+1,hp,joy),sol(index+1,hp-lost[index],joy+enjoy[index]));
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int lose;
        cin>>lose;
        lost[i]=lose;
    }
    for(int i=0;i<N;i++)
    {
        int joy;
        cin>>joy;
        enjoy[i]=joy;
    }

    // for(int i=0;i<N;i++)
    // {
    //     // 현재 i index에서 기쁨을 얻을 수 있을 때 마다
    //     // 최대 값을 저장. 
    //     for(int j=99;j>=0;j--)
    //     {
    //         //체력을 잃는 경우가 현재 인덱스 값보다 크면 얻을 수 없는 경우.
    //         if(lost[i]>j)break;
    //         // 이 체력에서 얻을 수 있는 가장 큰 기쁨을 저장.
    //         dp[j]=max(dp[j],dp[j-lost[i]]+enjoy[i]);
    //     }
    // }
    // cout<<dp[99]<<"\n";

    int result=sol(0,100,0);
    cout<<result<<"\n";

    return 0;
}