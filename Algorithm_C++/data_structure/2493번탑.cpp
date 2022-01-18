#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int N;
vector<int> tower;
stack<pair<int,int> > chk;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int height;
        cin>>height;
        // 각 탑의 높이 저장.
        tower.push_back(height);
    }
    for(int i=0;i<N;i++)
    {
        // 비교하려는 탑이 비거나 
        // 비교하는 탑의 높이가 현재 탑의 높이보다 큰 경우 
        // 멈춤.
        // 그 전까지는 비교하는 탑을 뺌.
        // 만약 9 6 7 인경우
        // 9 -> 6
        // 6 -> 0 이 됨.
        
        while(1)
        {   
            // 더 이상 비교할 타워가 없는 경우
            if(chk.empty()) break;
            // 자신보다 높은 타워를 만난 경우
            if(chk.top().second >= tower[i]) break;
            
            chk.pop();
        } 
        // 비교하는 탑의 stack이 빈 경우.
        // 자신의 높이보다 다 낮은 경우.
        if(chk.empty())cout<<0<<" ";
        // 현재 탑의 높이보다 큰 탑의 인덱스 출력.
        else cout<<chk.top().first<<" ";

        // 비교 탑 stack에 자신의 정보 넣기.
        // 자신의 index, height
        chk.push(make_pair(i+1,tower[i]));

    }

    cout<<"\n";

    return 0;
}