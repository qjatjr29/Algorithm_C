#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n;
vector<pair<int,int> > work;
int ans;
void outSourcing(int index,int cost)
{
    for(int i=index;i<n;i++)
    {
        if(i + work[i].second >n) continue;
        ans=max(ans,cost+work[i].first);
        outSourcing(i+work[i].second,cost+work[i].first);
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int time, cost;
        cin>>time>>cost;
        work.push_back(make_pair(cost,time));
    }
    outSourcing(0,0);
    cout<<ans<<"\n";


    return 0;
}