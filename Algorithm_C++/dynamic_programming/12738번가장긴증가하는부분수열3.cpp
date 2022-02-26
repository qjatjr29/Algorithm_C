#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<int> A;
vector<int> dp;
void sol()
{
    dp.push_back(A[0]);
    for(int i=1;i<N;i++)
    {
        if(dp[dp.size()-1] < A[i]) dp.push_back(A[i]);
        else 
        {
            int idx = lower_bound(dp.begin(),dp.end(),A[i]) - dp.begin();
            dp[idx] = A[i];
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    A = vector<int>(N+1);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    sol();
    cout<<dp.size()<<"\n";
    return 0;
}