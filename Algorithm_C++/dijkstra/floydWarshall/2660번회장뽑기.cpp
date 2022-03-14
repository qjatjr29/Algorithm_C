#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int members;
int chairman[51][51];
vector<int> answer;
void floyd()
{
    for(int i=1;i<=members;i++)
    {
        for(int j=1;j<=members;j++)
        {
            for(int k = 1; k<=members;k++)
            {
                if(j==k) continue;
                chairman[j][k] = min(chairman[j][k], chairman[j][i] + chairman[i][k]);
            }
        }
    }

    int value = INT_MAX;
    for(int i=1;i<=members;i++)
    {
        int temp = 0;
        for(int j=1;j<=members;j++)
        {
            temp = max(chairman[i][j],temp);
        }
        if(temp == value) answer.push_back(i);
        else if(temp<value) 
        {
            value = temp;
            answer.clear();
            answer.push_back(i);
        }
    }

    cout<<value<<" "<<answer.size()<<'\n';
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>members;

    for(int i=1;i<51;i++)
    {
        for(int j=1;j<51;j++)
        {
            if(i==j) continue;
            chairman[i][j] = 100;
        }
    }

    while(1)
    {
        int friend1,friend2;
        cin>>friend1 >> friend2;
        if(friend1 == -1 && friend2 == -1 ) break;
        chairman[friend1][friend2] = 1;
        chairman[friend2][friend1] = 1;
    }
    
    floyd();

    return 0;
}