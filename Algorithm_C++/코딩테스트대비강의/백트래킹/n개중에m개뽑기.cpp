#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N,M;
vector<int> numbers;
void Combination(int index,int preNum)
{
    if(index>=M)
    {
        for(int i=0;i<M;i++)
        {
            cout<<numbers[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=preNum+1;i<=N;i++)
    {
        numbers.push_back(i);
        Combination(index+1,i);
        numbers.pop_back();
    }
    return;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;
    Combination(0,0);
    

    return 0;
}