#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

int N;
vector<int> lines;
vector<int> dp;
int answer;
void setLine()
{
    dp.push_back(lines[1]);
    for(int i=2;i<=N;i++)
    {
        if(dp[dp.size()-1] < lines[i]) dp.push_back(lines[i]);
        else
        {
            int idx = lower_bound(dp.begin(),dp.end(),lines[i]) - dp.begin();
            dp[idx] = lines[i];
        }
    }
    answer = N - dp.size();
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    lines = vector<int>(N+1);
    for(int i=1;i<=N;i++)
    {
        cin>>lines[i];
    }
    setLine();
    cout<<answer<<'\n';

    return 0;
}