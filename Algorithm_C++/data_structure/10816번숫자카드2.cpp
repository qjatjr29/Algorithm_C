#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int N,M;
vector<int> card;
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
        int rightIndex=upper_bound(card.begin(),card.end(),findNumber)-card.begin();
        int leftIndex=lower_bound(card.begin(),card.end(),findNumber)-card.begin();
        cout<<rightIndex-leftIndex<<" ";
    }
    cout<<"\n";
    return 0;
}