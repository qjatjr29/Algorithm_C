#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int N; // 메뉴의 종류
int C; // 각 메뉴마다의 칼로리
vector<int> foods;
bool visited[8001];
vector<int> dp;
int answer;
void setFood(int cnt,int idx)
{
    if(cnt==3)
    {
        bool chk = false;
        for(int i=0;i<3;i++)
        {
            if(visited[dp[i]]==false)
            {
                chk = true;
                break;
            }
        }
        if(chk)
        {
            answer++;
            for(int i=0;i<3;i++)
            {
                visited[dp[i]] = true;
            }
        }
        return;
    }

    for(int i=idx+1;i<N;i++)
    {
        dp.push_back(i);
        setFood(cnt+1,i);
        dp.pop_back();
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>C;
        foods.push_back(C);
    }
    setFood(0,-1);
    cout<<answer<<"\n";
    return 0;
}