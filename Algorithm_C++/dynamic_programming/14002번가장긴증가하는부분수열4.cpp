#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N;
vector<int> numbers;
vector<int> dp;
vector<int> dpIndex;
vector<int> answer;
void sol()
{
    dp.push_back(numbers[0]);
    // 증가하는 수열의위치를 알려주는 수열.
    dpIndex[0] = 0;
    for(int i=1;i<N;i++)
    {
        if(dp[dp.size()-1] < numbers[i]){
            dp.push_back(numbers[i]);
            dpIndex[i] = dp.size()-1;
        } 
        else
        {
            int idx = lower_bound(dp.begin(),dp.end(),numbers[i]) - dp.begin();
            dp[idx] = numbers[i];
            dpIndex[i] = idx;
        }
    }
    int size = dp.size()-1;
    for(int i=N-1;i>=0;i--)
    {
        if(size==dpIndex[i])
        {
            answer.push_back(numbers[i]);
            size--;
        }
    }
    cout<<answer.size()<<"\n";
    for(int i=answer.size()-1;i>=0;i--)
    {
        cout<<answer[i]<<" "; 
    }
    cout<<"\n";

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    numbers = vector<int>(N);
    dpIndex = vector<int>(N);
    for(int i=0;i<N;i++)
    {
        cin>>numbers[i];
    }
    sol();

    return 0;
}