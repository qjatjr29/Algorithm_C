#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,K;
vector<int> visited;
int find_time;
int time_count;
void find_brother(){
    queue<pair<int,int>> pq;
    pq.push(make_pair(0,N));
    find_time=987654321;
    visited=vector<int>(100001,987654321);
    while (1)
    {
        if(pq.empty())break;
        int curCount=pq.front().first;
        int curNode=pq.front().second;
        pq.pop();
       
        // 기저 사례
        // 범위 , 이미 최소 경우가 아닌경우
        if(curNode<0 || curNode>100000 || curCount>find_time)continue;
        
        // 이미 방문한 노드인데 저번에 방문했을 때가 더 빨랐을 때는 넘긴다.
        if(visited[curNode]>=curCount)
        {
            visited[curNode]=curCount;
        }
        else continue;

        // 도착한 경우
        if(curNode==K)
        {
            if(find_time>curCount)
            {
                find_time=curCount;
                time_count=1;
            }
            else if(find_time==curCount)
            {
                time_count++;
            }
        }
        else
        {
            curCount++;
            if(curNode-1 >=0)
            {
                pq.push(make_pair(curCount,curNode-1));
                
            }
            if(curNode<K && curNode+1<=100000)
            {
                pq.push(make_pair(curCount,curNode+1));
            }
            if(curNode<K && curNode*2 <=100000)
            {
                pq.push(make_pair(curCount,curNode*2));
            }
        }
        

    }
    

}
int main()
{  
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>K;

    find_brother();
    cout<<find_time<<"\n";
    cout<<time_count<<"\n";

    return 0;
}