#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int consumers[1000001];
int leader,member;
int result;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int consumer;
        cin>>consumer;
        consumers[i]=consumer;
    }
    cin>>leader>>member;
    for(int i=1;i<=n;i++)
    {
        int can_consumer=consumers[i];
        can_consumer -= leader;
        if(can_consumer<=0) result++;
        else
        {
            int count=can_consumer/member;
            if(can_consumer % member ==0)
            {
                result += (count+1);
            }
            else result+=(count+2);
        }
    }
    cout<<result<<"\n";
    return 0;
}