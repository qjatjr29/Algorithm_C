#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int MOD = 1000000000;
int N;
// 2 ^ 10 개.
int dp[10][101][1 << 10];
long long answer;
int sol(int cnt,int chk,int idx)
{
    if(cnt == N)
    {
        if(chk == 1023) return 1;
        else return 0;
    }

    int cur = dp[idx][cnt][chk];
    if(cur != -1) return cur;

    int rtn = 0;
    if(idx - 1 >=0)
    {
        rtn += sol(cnt+1,chk | (1 << (idx-1)),idx-1);
    }
    if(idx + 1 < 10)
    {
        rtn += sol(cnt+1,chk | (1 << (idx+1)),idx+1);
    }
    rtn %= MOD;
    dp[idx][cnt][chk] = rtn;
    return rtn;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
   
    for(int i=1;i<=9;i++)
    {
        memset(dp,-1,sizeof(dp));
        answer += sol(1,1<<i,i);
        answer %= MOD;
    }
    cout<<answer<<"\n";
   
    return 0;
}
