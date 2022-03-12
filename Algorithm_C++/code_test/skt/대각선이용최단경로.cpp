#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

const int MAX = 10000019;
int dp[251][251];
int solution(int width,int height,vector<vector<int> > diagonals)
{
    int answer = 0;
    
    for(int i=0;i<=width;i++)
    {
        dp[0][i] = 1;
    }
    for(int i=0;i<=height;i++)
    {
        dp[i][0] =1;
    }
    dp[0][0]=0;
    for(int i=1;i<=width;i++)
    {
        for(int j=1;j<=height;j++)
        {
            dp[i][j]= dp[i-1][j] + dp[i][j-1];
        }
    }

    for(int i=0;i<=width;i++)
    {
        for(int j=0;j<=height;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0;i<diagonals.size();i++)
    {
        int x= diagonals[i][0];
        int y = diagonals[i][1];
        int temp = dp[width-x][height-y];
        long long pre = (dp[x][y] * temp) % MAX;
        long long left, down;
        left = 0;
        down = 0;
        if(x + 1 <= width)
        {
            temp = dp[width-x-1][height-y+1];
            left = (dp[x+1][y-1] * temp) % MAX;
        }
        if(y + 1 <=height)
        {
            temp = dp[width-x+1][height-y-1];
            down = (dp[x-1][y+1] * temp) % MAX;
        }
        long long sum = (pre + left) %MAX;
        sum = (sum + down) % MAX;
    
        answer += sum;
        answer % MAX;
    } 

    return answer;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);


    return 0;
}