#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<int> swit;
vector<int> bulbs;
vector<int> ordinary;
vector<int> dp;
vector<int> dpIndex;
void sol()
{
    dp.push_back(bulbs[1]);
    dpIndex[1] = 0;
    for(int i=2;i<=N;i++)
    {
        if(dp[dp.size()-1] < bulbs[i])
        {
           dp.push_back(bulbs[i]);    
           dpIndex[i] = dp.size()-1; 
        } 
        else
        {
            int idx = lower_bound(dp.begin(),dp.end(),bulbs[i]) - dp.begin();
            dp[idx] = bulbs[i];
            dpIndex[i] = idx;
        }
    }
    vector<int> answer;
    int size = dp.size()-1;
    for(int i=N;i>0;i--)
    {
        if(dpIndex[i]==size)
        {
           answer.push_back(ordinary[bulbs[i]]);
           size--;     
        }
    }
    sort(answer.begin(),answer.end());
    cout<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++)
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

    swit = vector<int>(N+1);
    bulbs = vector<int>(N+1);
    ordinary = vector<int>(N+1);
    dpIndex = vector<int>(N+1);
    for(int i=1;i<=N;i++)
    {
        int swi;
        cin>>swi;
        swit[swi] = i;
    }
    for(int i=1;i<=N;i++)
    {
        int light;
        cin>>light;
        int idx = swit[light];
        bulbs[idx] = i;
        ordinary[i] = light;
    }
    sol();


    return 0;
}