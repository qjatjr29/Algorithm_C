#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int N;
vector<int> numbers;
vector<int> dp;
void sol()
{
    dp.clear();
    dp.push_back(numbers[0]);
    for(int i=1;i<N;i++)
    {
        if(dp[dp.size()-1] < numbers[i])
        {
            dp.push_back(numbers[i]);
        }
        else
        {
            int idx = lower_bound(dp.begin(),dp.end(),numbers[i])-dp.begin();
            dp[idx] = numbers[i];
        }
    }
    cout<<dp.size()<<"\n";
    return;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    while(cin>>N)
    {
        numbers = vector<int>(N,0);

        for(int i=0;i<N;i++)
        {
            cin>>numbers[i];
        }
        sol();
    }
    

    return 0;
}