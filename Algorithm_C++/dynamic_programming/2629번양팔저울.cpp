#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int weightNumber;
vector<int> weights;
int boll;
vector<char> answer;
// 주어진 추로 무게를 측정할 수 있는지 없는지 확인.
// 주어진 추로 측정할 수 있는 무게의 최대값은 30 * 500
bool dp[31][15001];
void setDP(int idx,int cost)
{
    // 추의 개수가 N개 넘어간 경우
    if(idx > weightNumber) return;
    // 이미 체크한 경우.
    if(dp[idx][cost]) return;
    dp[idx][cost] = true;
    // 추들을 같은 쪽에 놓는 경우 - 무게가 계속 추가
    setDP(idx+1,cost+weights[idx]);
    // 현재 추를 선택하지 않는 경우
    setDP(idx+1,cost);
    // 현재 추를 반대쪽에 놓는 경우 ( 추들의 차이를 구하는 경우 )
    setDP(idx+1,abs(cost - weights[idx]));
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>weightNumber;
    weights = vector<int>(weightNumber+1,0);
    for(int i=0;i<weightNumber;i++)
    {
        cin>>weights[i];
    }
    setDP(0,0);
    cin>>boll;
    
    for(int i=0;i<boll;i++)
    {
        int number;
        cin>>number;
        // 구슬의 무게가 추로 잴 수 있는 무게를 넘어가는 경우.
        if(number > 15000) 
        {   
            answer.push_back('N');
            continue;
        }
        // 주어진 추를 다 사용하든 안하든 구슬의 무게를 못 구하는 경우.
        if(dp[weightNumber][number]==false) answer.push_back('N');
        else answer.push_back('Y');
    }
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}