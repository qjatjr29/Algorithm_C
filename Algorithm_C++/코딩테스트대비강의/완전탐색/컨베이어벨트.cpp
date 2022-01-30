#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n,t;
vector<int> belt1,belt2;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>t;
    belt1=vector<int>(n,0);
    belt2=vector<int>(n,0);
    for(int i=0;i<n;i++)
    {
        int number;
        cin>>number;
        belt1[i]=number;
    }
    for(int i=n-1;i>=0;i--)
    {
        int number;
        cin>>number;
        belt2[i]=number;
    }
    while(1)
    {
        if(t<=0)break;

        int temp1=belt1[n-1];
        int temp2=belt2[0];
        for(int i=n-1;i>0;i--)
        {
            belt1[i]=belt1[i-1];
        }
        for(int i=0;i<n-1;i++)
        {
            belt2[i]=belt2[i+1];
        }
        belt1[0]=temp2;
        belt2[n-1]=temp1;
        t--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<belt1[i]<<" ";
    }
    cout<<"\n";
    for(int i=n-1;i>=0;i--)
    {
        cout<<belt2[i]<<" ";
    }
    cout<<"\n";
    return 0;
}