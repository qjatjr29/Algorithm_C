#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N,K;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>K;
    queue<int> q;
    queue<int> result;
    for(int i=1;i<=N;i++)
    {
        q.push(i);
    }
    int count=0;
    while(1)
    {
        if(q.empty())break;
        count++;
        int top=q.front();
        if(count==K)
        {
            count=0;
            result.push(top);
        }
        else q.push(top);
        q.pop();
    }
    int person=result.front();
    result.pop();
    cout<<"<"<<person;
    while(1)

    {
        if(result.empty())break;
        person=result.front();
        result.pop();
        cout<<", "<<person;
    }
    cout<<">\n";
    return 0;
}
