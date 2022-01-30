#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n, bombx,bomby;
vector<vector<int> > map;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
void bomb(int x,int y)
{
    vector<vector<int> > temp;
    temp=vector<vector<int> >(n+1,vector<int>(n+1,0));
    int maxLen=map[x][y];
    map[x][y]=0;
    for(int i=0;i<4;i++)
    {
        int nx,ny;
        nx=x+dx[i];
        ny=y+dy[i];
        int count=1;
        while(1)
        {
            if(count>=maxLen) break;
            if(nx<0 || nx>=n || ny<0 || ny>=n) break;
            map[nx][ny]=0;
            nx+=dx[i];
            ny+=dy[i];
            count++;
        }
    }
    for(int i=0;i<n;i++)
    {
        int endOfTemp=n-1;
        for(int j=n-1;j>=0;j--)
        {
            if(map[j][i]!=0)
            {
                temp[endOfTemp][i]=map[j][i];
                endOfTemp--;
            }
        }
    }
    map=temp;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    map=vector<vector<int> >(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            map[i][j]=num;
        }
    }
    cin>>bombx>>bomby;
    bomb(bombx-1,bomby-1);
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