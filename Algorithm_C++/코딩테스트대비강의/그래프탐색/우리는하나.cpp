#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,k,u,d;
int maxCity;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<vector<int> > city;
vector<vector<bool> > visited;
vector<vector<bool> > temp;
vector<pair<int,int> > selectCity;
bool can_go(int x,int y,int value)
{
    if(x<0 || x>=n || y<0 ||y>=n)return false;
    else if(temp[x][y]) return false;
    else if(abs(value-city[x][y])<u || abs(value-city[x][y])>d) return false;
    return true;
}
void bfs()
{
    
    temp=vector<vector<bool> >(9,vector<bool>(9,false));
    queue<pair<int,int> > cityQ;
    for(int i=0;i<selectCity.size();i++)
    {
        cityQ.push(make_pair(selectCity[i].first,selectCity[i].second));
        temp[selectCity[i].first][selectCity[i].second]=true;
    }
    int count=0;
    
    while(1)
    {
        if(cityQ.empty())break;
        count++;
        int curX=cityQ.front().first;
        int curY=cityQ.front().second;
        cityQ.pop();
        for(int i=0;i<4;i++)
        {
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(can_go(nx,ny,city[curX][curY]))
            {
                temp[nx][ny]=true;
                cityQ.push(make_pair(nx,ny));
            }
        }
    }
    maxCity=max(maxCity,count);
}
void Choose(int idx)
{

    if(idx==k)
    {
        bfs();
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==false)
            {
                selectCity.push_back(make_pair(i,j));
                visited[i][j]=true;
                Choose(idx+1);
                selectCity.pop_back();
                visited[i][j]=false;
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n>>k>>u>>d;
    city=vector<vector<int> >(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>city[i][j];
        }
    }
    visited=vector<vector<bool> >(9,vector<bool>(9,false));
    Choose(0);
    cout<<maxCity<<"\n";


    return 0;
}