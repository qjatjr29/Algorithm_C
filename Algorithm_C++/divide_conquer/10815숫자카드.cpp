#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
vector<int> card;
int divideConquer(int value,int left,int right)
{
    if(left>=right)return 0;
    int mid=(left+right)/2;
    if(card[mid]==value) return 1;
    if(card[mid]<value)
    {
        return divideConquer(value,mid+1,right);
    }
    else return divideConquer(value,left,mid);
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int i=0;i<N;i++)
    {
        int number;
        cin>>number;
        card.push_back(number);
    }
    sort(card.begin(),card.end());
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int findNumber;
        cin>>findNumber;
        cout<<divideConquer(findNumber,0,card.size())<<" ";
    }
    cout<<"\n";

    return 0;
}