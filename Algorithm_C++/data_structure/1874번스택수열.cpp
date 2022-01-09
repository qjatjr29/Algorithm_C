#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;
stack<int> numbers;
int nums[100001];
int _count=1;
vector<char> result;
void make_stack()
{
    for(int i=1;i<=n;i++)
    {
        numbers.push(i);
        result.push_back('+');
        while(!numbers.empty() && numbers.top()==nums[_count])
        {
           
            numbers.pop();
            result.push_back('-');
            _count++;
            
        }
    }
}  

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int number;
        cin>>number;
        nums[i]=number;
    }
    make_stack();
    if(!numbers.empty())cout<<"NO"<<'\n';
    else 
    {
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<'\n';
        }
    }
    
    return 0;
}