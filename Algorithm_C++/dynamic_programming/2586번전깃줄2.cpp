#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int N;
vector<pair<int,int> > lines;
vector<int> answer;
vector<int> dp;
int dpIndex[100001];
void sol()
{
    dp.push_back(lines[0].second);
    dpIndex[0] = 0;
    for(int i=1;i<N;i++)
    {
        if(dp[dp.size()-1] < lines[i].second)
        {
            dp.push_back(lines[i].second);
            dpIndex[i] = dp.size()-1;
        }
        else
        {
            int idx = lower_bound(dp.begin(),dp.end(),lines[i].second) - dp.begin();
            dp[idx] = lines[i].second;
            dpIndex[i] = idx; 
        }
    }
    
    int size = dp.size()-1;
    for(int i=N-1;i>=0;i--)
    {
        if(dpIndex[i] == size)
        {
            size--;
            continue;
        }
        else
        {
            answer.push_back(lines[i].first);
        }
    }
    sort(answer.begin(),answer.end());
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    lines = vector<pair<int,int> >(N);
    for(int i=0;i<N;i++)
    {
        int l,r;
        cin>>l>>r;
        lines[i] = make_pair(l,r);
    }

    sort(lines.begin(),lines.end());
    sol();
    cout<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<"\n";
    }
    return 0;
}