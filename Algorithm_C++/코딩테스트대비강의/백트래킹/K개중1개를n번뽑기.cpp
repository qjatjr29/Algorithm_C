#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int K,N;
vector<int> numbers;
void Choose(int count)
{
    if(count>N)
    {
        for(int i=0;i<numbers.size();i++)
        {
            cout<<numbers[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=K;i++)
    {
        numbers.push_back(i);
        Choose(count+1);
        numbers.pop_back();
    }
    return;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>K>>N;
    Choose(1);
    return 0;
}