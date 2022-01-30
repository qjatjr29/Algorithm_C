#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n,m,k;
vector<vector<int> > map;
bool chk(int col)
{
    for(int i=k-1;i<=k+m-2;i++)
    {
        if(map[col][i]==1)return false;
    }
    return true;
}
int main()
{

    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m>>k;
    map=vector<vector<int> >(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }
    int col;
    for(int i=1;i<n;i++)
    {
        if(chk(i)==false)
        {
            col=i-1;
            break;
        }
    }
    for(int i=k-1;i<=k+m-2;i++)
    {
        map[col][i]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}