#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

int n;
vector<int> ports;
vector<int> dp;
int answer = 0;
void sol()
{
    dp.push_back(ports[1]);
    for(int i=2;i<=n;i++)
    {
        int curPort = ports[i];
        if(dp[dp.size()-1] < curPort ) dp.push_back(curPort);
        else
        {
            int idx = lower_bound(dp.begin(),dp.end(),curPort) - dp.begin();
            dp[idx] = curPort;
        }
    }
    answer = dp.size();
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n;
    ports = vector<int> (n+1);
    for(int i=1;i<=n;i++)
    {
        int number;
        cin>>number; 
        ports[i] = number;
    }
    sol();
    cout<<answer<<"\n";
    return 0;
}