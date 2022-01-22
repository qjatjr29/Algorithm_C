#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

const long long MAXNUM=9876543210;

int N;
queue<int> numbers;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    if(N<10)
    {
        cout<<N<<"\n";
        return 0;
    }
    for(int i=1;i<=9;i++)
    {
        numbers.push(i);
    }
    int count=9;
    long long result;
    while(1)
    {
        if(numbers.empty())break;
        if(count==N)break;
        long long curNumber=numbers.front();
        numbers.pop();
        
        for(int i=0;i<=9;i++)
        {
            if((curNumber%10)<=i)break;
            result=curNumber*10 + i;
            if(result>MAXNUM)break;
            //cout<<"curNumber * 10 +i : "<<result<<"\n";
            numbers.push(result);
            count++;
            if(count==N)break; 
        }
    }

    if(count==N)cout<<result<<"\n";
    else cout<<-1<<"\n";

    return 0;
}