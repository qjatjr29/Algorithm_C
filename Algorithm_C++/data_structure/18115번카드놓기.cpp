#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> result;
deque<int> card;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int state;
        cin>>state;
        result.push_back(state);
    }
    // An 은 항상 1. -> 1을 맨 위에서 꺼냄.
    // card에 값 넣고 시작.
    reverse(result.begin(),result.end());
    for(int i=1;i<=N;i++)
    {
        // i번째 수를 맨 앞에서 꺼냄.
        if(result[i-1]==1)
        {
            card.push_front(i);
        }
        // i번째 수를 두번째 위에서 꺼냄.
        // 맨앞에 있는 수 빼고 i넣고 원래 있던 수를 다시 앞에 넣기.
        else if(result[i-1]==2)
        {
            int temp=card.front();
            card.pop_front();
            card.push_front(i);
            card.push_front(temp);
        }
        // 맨 뒤에서 꺼냄.
        else if(result[i-1]==3)
        {
            card.push_back(i);
        }
    }
    
    for(int i=0;i<N;i++)
    {
        cout<<card.front()<<" ";
        card.pop_front();
    }
    cout<<"\n";
    return 0;
}