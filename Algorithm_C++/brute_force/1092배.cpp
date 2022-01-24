#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N,M;
bool chk=true;
vector<int> crane;
vector<int> box_weight;
int can_crane[51];
long long min_time;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    crane=vector<int>(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>crane[i];
    }
    sort(crane.begin(),crane.end());
    
    cin>>M;
    box_weight=vector<int>(M,0);
    for(int i=0;i<M;i++)
    {
        // int weight;
        // cin>>weight;
        // box_weight.push(weight);
        cin>>box_weight[i];
    }
    sort(box_weight.begin(),box_weight.end());
    
    if(crane[N-1]<box_weight[M-1])
    {
        cout<<"-1"<<"\n";
        return 0;
    }

    while ((1))
    {
        if(box_weight.empty())break;
        min_time++;
        for(int i=N-1;i>=0;i--)
        {
            for(int j=box_weight.size()-1;j>=0;j--)
            {
                if(crane[i]>=box_weight[j])
                {
                    box_weight.erase(box_weight.begin()+j,box_weight.begin()+j+1);
                    break;
                }
            }
        }
    }
    cout<<min_time<<"\n";
    // while(1)
    // {
    //     if(box_weight.empty())break;
    //     min_time++;
    //     for(int i=0;i<N;i++)
    //     {
    //         if(box_weight.empty())break;
    //         int weight=box_weight.top();
    //         if(weight<=crane[i]) box_weight.pop();
    //         else break;
    //     }
    // }
    // cout<<min_time<<"\n";


    return 0;
}