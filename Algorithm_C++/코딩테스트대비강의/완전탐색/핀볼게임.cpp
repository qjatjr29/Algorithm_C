#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int> >board;
int min_time;
// 상하 좌우.
// 1을 만났을 때 -> (1,2)  (0,3) -> dir = 3-dir
// 2을 만났을 때 -> (1,3)  (0,2) -> dir = (dir+2)%4
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int move(int x,int y,int dir)
{
    int count=1;
    while(1)
    {
        if(x<0 || x>=n || y<0 || y>=n ) break;

        if(board[x][y]==1)
        {
            dir=3-dir;
        }
        else if(board[x][y]==2)
        {
            dir= (dir+2)%4;
        }
        x+=dx[dir];
        y+=dy[dir];     
        count++;
    }
    return count;
}
void pinball()
{
    for(int i=0;i<n;i++)
    {
        min_time=max(min_time,move(0,i,1));
        min_time=max(min_time,move(n-1,i,0));
        min_time=max(min_time,move(i,0,3));
        min_time=max(min_time,move(i,n-1,2));
    }
    cout<<min_time<<"\n";
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    board=vector<vector<int> >(n+1,vector<int>(n+1,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
        }
    }

    pinball();

    return 0;
}