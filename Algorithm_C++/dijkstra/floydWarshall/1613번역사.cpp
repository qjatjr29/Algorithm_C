#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n,k,s;
int dp[401][401];
void setDP()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                // j>i 인 경우
               if(dp[j][i] == -1 && dp[i][k] == -1) dp[j][k] = -1;
               // j<i 인 경우
               else if(dp[j][i] == 1 && dp[i][k] ==1 )dp[j][k] = 1; 
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>k;
    
    for(int i=0;i<k;i++)
    {
        int pre,next;
        cin>>pre>>next;
        dp[pre][next] = -1;
        dp[next][pre] = 1;
    }
    setDP();
    cin>>s;
    for(int i=0;i<s;i++)
    {
        int accident1,accident2;
        cin>>accident1>>accident2;
        cout<<dp[accident1][accident2]<<"\n";
    }


    return 0;
}