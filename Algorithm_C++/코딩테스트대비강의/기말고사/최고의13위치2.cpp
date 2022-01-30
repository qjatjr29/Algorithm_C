#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n;
vector<vector<int> > map;
vector<int> ans;
vector<int> chk;
void calc(int col)
{
    
    for(int i=0;i<chk.size();i++)
    {
        int count=0;
        for(int j=chk[i];j<chk[i]+3;j++)
        {
            if(map[col][j]==1) count++;
        }
        ans.push_back(count);
    }
}
void Choose(int col,int index)
{

    if(index+3>n)
    {
        calc(col);
        return;
    }
    for(int i=index+1;i<=n-2;i++)
    {
        chk.push_back(i);
        Choose(col,index+2);
        chk.pop_back();
    }
}
int main()
{

    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    map=vector<vector<int> >(n+1,vector<int>(n+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        Choose(i,0);
    }
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()-1]+ans[ans.size()-2]<<"\n";
    
    return 0;
}