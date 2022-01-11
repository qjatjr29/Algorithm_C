#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N,M;
vector<vector<pair<int,int>>> roads;
int ans;
vector<int> cows;
void moveRoad()
{
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(-1,0));
    cows[1]=0;
    while(1)
    {
        if(pq.empty())break;
        int curNode=-pq.top().first;
        int curCowCount=pq.top().second;

        pq.pop();
        
        // 현재 노드와 연결된 길.
        for(int i=0;i<roads[curNode].size();i++)
        {
            int nextNode=roads[curNode][i].first;
            int nextCount=roads[curNode][i].second;
            if(cows[nextNode]>cows[curNode]+nextCount)
            {
                cows[nextNode]=cows[curNode]+nextCount;
                pq.push(make_pair(-nextNode,nextCount));
            }
        }

    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;
    roads=vector<vector<pair<int,int>>>(N+1,vector<pair<int,int>>());
    cows.resize(N+1,987654321);
    for(int i=0;i<M;i++)
    {
        int placeA,placeB,cowCount;
        cin>>placeA>>placeB>>cowCount;
        roads[placeA].push_back(make_pair(placeB,cowCount));
        roads[placeB].push_back(make_pair(placeA,cowCount));
    }
    moveRoad();
    cout<<cows[N]<<"\n";
    return 0;
}