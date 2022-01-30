#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int n,m,t;
//상좌우하
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
vector<vector<pair<pair<int,int>,pair<int,int> > > > bead;
vector<vector<pair<pair<int,int>,pair<int,int> > > >nextBead;
void move(int x,int y,int dir,int cost,int idx)
{
    int nx=x+dx[dir];
    int ny=y+dy[dir];
    // 넘어간 경우.
    if(nx<=0 || nx>n || ny<=0 || ny>n)
    {
        dir=3-dir;
        nextBead[x][y].first.first++;
        if(nextBead[x][y].first.first>=2)
        {
            nextBead[x][y].first.first=1;
            if(nextBead[x][y].first.second<idx)
            {
                nextBead[x][y].first.second=idx;
                nextBead[x][y].second.first=dir;
            }
            nextBead[x][y].second.second += cost;
        }
        else
        {
            nextBead[x][y].first.second=idx;
            nextBead[x][y].second.first=dir;
            nextBead[x][y].second.second=cost;
        }
    }
    else
    {
       nextBead[nx][ny].first.first++;
        if(nextBead[nx][ny].first.first>=2)
        {
            nextBead[nx][ny].first.first=1;
            if(nextBead[nx][ny].first.second<idx)
            {
                nextBead[nx][ny].first.second=idx;
                nextBead[nx][ny].second.first=dir;
            }
            nextBead[nx][ny].second.second += cost;
        }
        else
        {
            nextBead[nx][ny].first.second=idx;
            nextBead[nx][ny].second.first=dir;
            nextBead[nx][ny].second.second=cost;
        }
    }
}
void moveAll()
{
    nextBead=vector<vector<pair<pair<int,int>,pair<int,int> > > >(n+1,vector<pair<pair<int,int>,pair<int,int> > >(n+1,make_pair(make_pair(0,0),make_pair(0,0))));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(bead[i][j].first.first==1)
            {
                move(i,j,bead[i][j].second.first,bead[i][j].second.second,bead[i][j].first.second);
            }
        }
    }
    
    bead=nextBead;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m>>t;
    bead=vector<vector<pair<pair<int,int>,pair<int,int> > > >(n+1,vector<pair<pair<int,int>,pair<int,int> > >(n+1));

    map<char,int> mapper;
    mapper['U']=0;
    mapper['D']=3;
    mapper['L']=1;
    mapper['R']=2;
    for(int i=0;i<m;i++)
    {
        int row,col,w;
        char dir;
        cin>>row>>col>>dir>>w;
        bead[row][col]=make_pair(make_pair(1,i),make_pair(mapper[dir],w));
    }

    // 벽에 부딪히면 방향 반대 (0,3) , (1,2) 
    // dir = 3-dir;

    while(t--)
    {
        moveAll();
    }
    int beadCount=0;
    int maxWeight=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(bead[i][j].first.first==1)
            {
                beadCount++;
                maxWeight=max(maxWeight,bead[i][j].second.second);
            }
        }
    }
    cout<<beadCount<<" "<<maxWeight<<'\n';
    return 0;
}