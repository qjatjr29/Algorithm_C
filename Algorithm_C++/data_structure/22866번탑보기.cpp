#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int N;
// 자신보다 큰 빌딩의 인덱스 저장.
vector<int> leftbuilding;
vector<int> rightbuilding;
stack<pair<int, int> > chk;
// 빌딩들의 높이 저장.
vector<int> buildings;
// 결과 값
pair<int,int> result[100001];
int rightHeight[100001];
void calc()
{
    for(int i=0;i<N;i++)
    {
        if(leftbuilding[i]==-1) 
        {
            result[i].first += 0;
        }
        else{
            result[i].second=leftbuilding[i];
            result[i].first += result[leftbuilding[i]].first + 1;
        }
    }
     for(int i=N-1;i>=0;i--)
    {
        if(rightbuilding[i]==-1) 
        {
            result[i].first += 0;
        }
        else{
            if(abs(result[i].second-i)>abs(rightbuilding[i]-i))
            {
                result[i].second=rightbuilding[i];
            }
            rightHeight[i]=rightHeight[rightbuilding[i]]+1;
            result[i].first +=  rightHeight[rightbuilding[i]] + 1;
        }
    }
}
void leftSide()
{
    for(int i=0;i<N;i++)
    {
        while(1)
        {   
            // 더 이상 비교할 빌딩이 없는 경우
            if(chk.empty()) break;
            // 자신보다 높은 빌딩를 만난 경우
            if(chk.top().second > buildings[i]) break;
            
            else chk.pop();
        } 

        // 비교하는 탑의 stack이 빈 경우.
        // 자신의 높이보다 다 낮은 경우.
        if(chk.empty()) leftbuilding[i]=-1;
        // 현재 빌딩의 높이보다 큰 탑의 인덱스 저장.
        else 
        {
            // result[i].second=leftbuilding[i];
            // result[i].first += result[leftbuilding[i]].first + 1;
            leftbuilding[i]=chk.top().first;
        }

        // 비교 탑 stack에 자신의 정보 넣기.
        // 자신의 index, height
        chk.push(make_pair(i,buildings[i]));
    }
}
void rightSide()
{
    for(int i=N-1;i>=0;i--)
    {
        while(1)
        {   
            // 더 이상 비교할 빌딩이 없는 경우
            if(chk.empty()) break;
            // 자신보다 높은 빌딩를 만난 경우
            if(chk.top().second > buildings[i]) break;
            
            else chk.pop();
        } 

        // 비교하는 탑의 stack이 빈 경우.
        // 자신의 높이보다 다 낮은 경우.
        if(chk.empty())rightbuilding[i]=-1;
        // 현재 빌딩의 높이보다 큰 탑의 인덱스 저장.
        else 
        {
            // rightHeight[i]=rightHeight[rightbuilding[i]]+1;
            // result[i].first += rightHeight[chk.top().first] + 1;
            // if(result[i].second == 987654321)
            // {
            //     result[i].second=chk.top().first;
            // }
            rightbuilding[i]=chk.top().first;
        }

        // 비교 탑 stack에 자신의 정보 넣기.
        // 자신의 index, height
        chk.push(make_pair(i,buildings[i]));

    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    buildings=vector<int>(N+1,0);
    for(int i=0;i<N;i++)
    {
        cin>>buildings[i];
        result[i].second=987654321;
    }
    leftbuilding=vector<int>(N+1,0);
    rightbuilding=vector<int>(N+1,0);
    leftSide();
    while(1)
    {
        if(chk.empty())break;
        chk.pop();
    }
    rightSide();
    calc();
    for(int i=0;i<N;i++)
    {
        if(result[i].first==0)
        {
            cout<<0<<"\n";
        }
        else cout<<result[i].first<<" "<<result[i].second+1<<"\n";
    }



    return 0;
}