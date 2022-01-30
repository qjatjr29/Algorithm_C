#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int a,b,c,d;
bool visited[101][101];
int ans;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>a>>b>>c>>d;

    for(int i=a;i<b;i++)
    {
        ans++;
        visited[i][i+1]=true;
    }
    for(int i=c;i<d;i++)
    {
        if(visited[i][i+1]==false)
        {
            ans++;
            visited[i][i+1]=true;
        }
    }
    cout<<ans<<"\n";
    return 0;
}