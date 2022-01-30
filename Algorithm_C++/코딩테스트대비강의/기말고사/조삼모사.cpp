#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;

int n;
vector<vector<int> > work;
vector<int> m;
vector<int> e;
int ans=987654321;
int calc()
{
    int mv = 0;
    int ev = 0; 
    for(int i=1;i<=n;i++)
    {
        bool chk=false;
        for(int j=0;j<m.size();j++)
        {
            if(i==m[j])
            {
                chk=true;
                break;
            }
        }
        if(!chk)e.push_back(i);
    }
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m.size();j++)
        {
            if(i==j) continue;
            mv+=work[m[i]][m[j]];
        }
    }
    for(int i=0;i<e.size();i++)
    {
        for(int j=0;j<e.size();j++)
        {
            if(i==j) continue;
            ev+=work[e[i]][e[j]];
        }
    }
    while(1)
    {
        if(e.empty()) break;
        e.pop_back();
    }
    return abs(mv-ev);
    
    
}
void Choose(int count,int index)
{

    if(count== n/2)
    {
        int gap=calc();
        ans=min(ans,gap);
        return;
    }
    for(int i=index+1;i<=n;i++)
    {
        m.push_back(i);
        Choose(count+1,i);
        m.pop_back();
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    work=vector<vector<int> >(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>work[i][j];
        }
    }
    Choose(0,0);
    cout<<ans<<"\n";

    return 0;
}