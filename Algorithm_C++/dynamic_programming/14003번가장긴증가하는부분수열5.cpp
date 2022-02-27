#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

int N;
vector<int> A;
vector<int> dp;
vector<int> dpIndex;
void sol()
{
    dp.push_back(A[0]);
    dpIndex[0] = 0;
    int size = 1;
    for(int i=1;i<N;i++)
    {
        if(dp[dp.size()-1]<A[i])
        {
            //size++;
            dp.push_back(A[i]);
            dpIndex[i]=dp.size()-1;
        }
        else
        {
            int idx = lower_bound(dp.begin(),dp.end(),A[i]) - dp.begin();
            dpIndex[i] = idx; 
            dp[idx] = A[i];
        }
    
    }
    
    vector<int> answer;
    size = dp.size()-1;
    for(int i=N-1;i>=0;i--)
    {
        if(dpIndex[i]==size)
        {
            size--;
            answer.push_back(A[i]);
        }
    }
    cout<<answer.size()<<"\n";
    for(int i=answer.size()-1;i>0;i--)
    {
        cout<<answer[i]<<" ";
    }
    cout<<answer[0]<<"\n";
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;

    A = vector<int>(N);
    dpIndex = vector<int>(N);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    sol();

    return 0;
}