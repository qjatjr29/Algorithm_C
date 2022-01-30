#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m,t;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
queue<pair<int,int> > boll;
vector<vector<int> > map;
vector<vector<int> > curCount;
vector<vector<int> > nextCount;
int result;
void move(int x,int y)
{
    int curNumber=0;
    int nextX=x;
    int nextY=y;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>0 && nx<=n && ny>0 && ny<=n)
        {
            // 이동해야 하는 곳을 찾은 경우.
            if(curNumber<map[nx][ny])
            {
                curNumber=map[nx][ny];
                nextX=nx;
                nextY=ny;
            }
        }
    }
    // cout<<"==="<<"\n";
    // cout<<"cur : "<<x<<" "<<y<<"\n";
    // cout<<"==="<<"\n";
    // cout<<"next : "<<nextX<<" "<<nextY<<"\n";
    // cout<<"==="<<"\n";
    nextCount[nextX][nextY]++;
}
void moveAll()
{
    nextCount=vector<vector<int> >(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(curCount[i][j]==1)
            {
                move(i,j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        curCount[i]=nextCount[i];
    }

}
void removeDuplicate()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //충돌이 있는 경우.
            if(curCount[i][j]>=2)
            {
                curCount[i][j]=0;
            }
        }
    }
}
void simulate()
{
    moveAll();
    removeDuplicate();
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m>>t;
    map=vector<vector<int> >(n+1,vector<int>(n+1,0));
    curCount=vector<vector<int> >(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int number;
            cin>>number;
            map[i][j]=number;
        }
    }
    for(int i=0;i<m;i++)
    {
        int bx,by;
        cin>>bx>>by;
        curCount[bx][by]=1;
    }
    while(t--)
    {
        simulate();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(curCount[i][j]==1)result++;
        }
    }
    cout<<result<<"\n";

    return 0;
}
