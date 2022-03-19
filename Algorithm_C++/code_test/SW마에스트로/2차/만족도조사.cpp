#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <stdio.h>
using namespace std;

int N,M,K;
double answer;
vector<vector<int> > friends;
vector<int> like;
vector<bool> visited;
// 만족도 조사를 하지 않는 친구들을 위한 함수.
int sol(int start)
{
    visited= vector<bool>(N+1,false);

    int rtn = 0;
    int cnt = 0;
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while(1)
    {
        if(q.empty()) break;
        int curIndex = q.front();
        q.pop();
        int size = int(friends[curIndex].size());
        for(int i=0;i<size;i++)
        {
            int nextIdx = friends[curIndex][i];
            if(visited[nextIdx]) continue;
            visited[nextIdx] = true;
            q.push(nextIdx);
            if(like[nextIdx]!=0) 
            {
                rtn += like[nextIdx];
                cnt ++;
            }
        
        }
    }
    if(cnt == 0 ) return 0;
    else
    {
        rtn = (int)rtn / (int)cnt;
        return rtn;
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M>>K;
    like = vector<int>(N+1,0);
    friends = vector<vector<int> >(N+1,vector<int>());
    for(int i=0;i<M;i++)
    {
        int idx, value;
        cin>>idx>>value;
        like[idx] = value;
    }

    for(int i=0;i<K;i++)
    {
        int friend1,friend2;
        cin>>friend1>>friend2;
        friends[friend1].push_back(friend2);
        friends[friend2].push_back(friend1);
    }

    double count = 0.0; 
    for(int i=1;i<=N;i++)
    {
        if(like[i]==0)
        {
            int temp = sol(i);
            if(temp!=0)
            {
                answer += sol(i);
                count++;
            }
        }
        else 
        {
            answer += like[i];
            count += 1.0;
        }
    }
    
    answer /= count;
    cout<<fixed<<setprecision(2)<<answer<<"\n";
    return 0;
}