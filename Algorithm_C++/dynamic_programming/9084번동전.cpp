#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

int T,N,M;
int dp[10001];
int coins[21];
void setDP()
{
    memset(dp,0,10001*sizeof(int));
    dp[0]=1;
    for(int i=0;i<N;i++)
    {
        for(int j=coins[i];j<=M;j++)
        {
            dp[j] += dp[j-coins[i]];
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>T;
    for(int testcase = 0; testcase<T;testcase++)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>coins[i];
        }
        cin>>M;
        setDP();
        cout<<dp[M]<<"\n";
    }
    
    return 0;
}