#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

vector<int> dp;
int coins[6] = {1,5,10,50,100,500};
int solution(int money,vector<int> costs)
{
    int answer = 0;
    dp = vector<int> (money+1,987654321);
    dp[0] = 0;
    for(int i=0;i<6;i++)
    {
        int value = coins[i];

        for(int j=value;j<=money;j++)
        {
            int preDp = dp[j-value] + costs[i];
            dp[j] = min(dp[j],dp[j-coins[i]] + costs[i]);
        }
    }
    answer = dp[money];
    // cout<<dp[money]<<"\n";


    return answer;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    vector<int> cost;
    //case 1
    // cost.push_back(1);
    // cost.push_back(4);
    // cost.push_back(99);
    // cost.push_back(35);
    // cost.push_back(50);
    // cost.push_back(1000);
    // solution(4578,cost);
    
    // case 2
    // cost.push_back(2);
    // cost.push_back(11);
    // cost.push_back(20);
    // cost.push_back(100);
    // cost.push_back(200);
    // cost.push_back(600);
    // solution(1999,cost);
    return 0;
}